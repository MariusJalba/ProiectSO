#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <inttypes.h>
#include <linux/limits.h>
#include <stdlib.h>
int fileExists(const char *snap)
{
    struct stat buf;
    if (stat(snap, &buf) == 0)
    {
        return 1;
    }
    return 0;
}
int openFile(char *snapFile)
{
    int snap;
    char buff[] = "Inode|FileName|Size\n";
    if (fileExists(snapFile))
    {
        remove(snapFile);
    }
    if ((snap = open(snapFile, O_RDWR | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR)) < 0)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(snap, buff, strlen(buff));
    return snap;
}
void writeToSnap(int fd, ino_t ino, char *filePath, off_t size)
{
    char buff[5000];
    sprintf(buff, "%ju|%s|%ju\n", (uintmax_t)ino, filePath, (uintmax_t)size);
    write(fd, buff, strlen(buff));
}
void TakeSnapshot(const char *nameDir, int snap, const char *InitDir)
{
    char abspath[PATH_MAX];
    DIR *Din;
    if ((Din = opendir(nameDir)) == NULL)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    realpath(nameDir, abspath);
    struct dirent *entry = NULL;
    while ((entry = readdir(Din)) != NULL)
    {
        char path[4353];
        struct stat st;
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            sprintf(path, "%s/%s", abspath, entry->d_name);
            if (stat(path, &st) != 0)
            {
                perror("stat");
                exit(EXIT_FAILURE);
            }
            if (S_ISREG(st.st_mode))
            {
                writeToSnap(snap, st.st_ino, path, st.st_size);
            }
            if (S_ISDIR(st.st_mode))
            {
                TakeSnapshot(path, snap, InitDir);
            }
        }
    }
    if (strcmp(nameDir, InitDir) == 0)
    {
        close(snap);
    }
}
void verifyDiff(const char *snapFile, const char *nameDir)
{
    int snap_actual = openFile("SnapshotActual.txt");
    TakeSnapshot(nameDir, snap_actual, nameDir);
    close(snap_actual);
    FILE *snap;
    FILE *snap_act;
    FILE *snap_r;
    char line[5000];
    char filePath[4096];
    off_t size;
    ino_t inode;
    struct stat st;
    int snap_size;
    int snap_ac_size;
    if ((snap = fopen(snapFile, "r")) == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    if ((snap = fopen("SnapshotActual.txt", "r")) == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    if (stat(snapFile, &st) != 0)
    {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    snap_size = st.st_size;
    if (stat("SnapshotActual.txt", &st) != 0)
    {
        perror("stat");
        exit(EXIT_FAILURE);
    }
    snap_ac_size = st.st_size;
    if (snap_ac_size > snap_size)
    {
        snap_r = snap_act;
    }
    else
    {
        snap_r = snap;
    }
    fgets(line, 5000, snap_r);
    while (fgets(line, 5000, snap_r))
    {
        inode = atoi(strtok(line, "|"));
        strcpy(filePath, strtok(NULL, "|"));
        size = atoi(strtok(NULL, "|"));
        if (stat(filePath, &st) != 0)
        {
            printf("Fisierul:%s a fost sters\n", filePath);
        }
        if (st.st_size - size != 0)
        {
            printf("Fisierul:%s si-a modificat dimensiunea\n", filePath);
        }
    }
    fclose(snap);
    remove(snapFile);
    rename("SnapshotActual.txt", "Snapshot.txt");
}
int main(int arcgv, char **arcg)
{
    if (arcgv != 2)
    {
        printf("Usage:./dir_snap <Input Directory>");
        exit(EXIT_FAILURE);
    }
    int snap = openFile("Snapshot.txt");
    TakeSnapshot(arcg[1], snap, arcg[1]);
    verifyDiff("Snapshot.txt", arcg[1]);
    return 0;
}
