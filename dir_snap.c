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
typedef struct files
{
    ino_t inode;
    char fpath[4096];
    off_t size;
} files;
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
files *addFile(files *f, const char *fileName, int *nr)
{
    int n = 10;
    FILE *fin;
    char linie[5000];
    if ((fin = fopen(fileName, "r")) == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    if ((f = malloc(sizeof(files) * n)) == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    fgets(linie, 5000, fin);
    while (fgets(linie, 5000, fin))
    {
        if (*nr < n)
        {
            f[(*nr)].inode = atoi(strtok(linie, "|"));
            strcpy(f[(*nr)].fpath, strtok(NULL, "|"));
            f[(*nr)++].size = atoi(strtok(NULL, "|"));
        }
        else
        {
            n = n * 2;
            if ((f = realloc(f, sizeof(files) * n)) == NULL)
            {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            f[(*nr)].inode = atoi(strtok(linie, "|"));
            strcpy(f[(*nr)].fpath, strtok(NULL, "|"));
            f[(*nr)++].size = atoi(strtok(NULL, "|"));
        }
    }
    fclose(fin);
    return f;
}
void compareSnapshots(files *f1, int n1, files *f2, int n2)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (f1[i].inode == f2[j].inode && strcmp(f1[i].fpath,f2[j].fpath)!=0)
            {
                printf("file %s was renamed to %s",f1[i].fpath,f2[i].fpath);
            }
        }
    }
}
void verifyDiff(const char *snapFile, const char *nameDir)
{
    files *f = NULL;
    files *fa = NULL;
    char sa[] = "SnapshotActual.txt";
    int n = 0;
    int na = 0;
    int snap_actual = openFile(sa);
    TakeSnapshot(nameDir, snap_actual, nameDir);
    close(snap_actual);
    f = addFile(f, snapFile, &n);
    fa = addFile(fa, sa, &na);
    remove(snapFile);
    rename(sa, snapFile);
    free(f);
    free(fa);
}
int main(int arcgv, char **arcg)
{
    if (arcgv != 2)
    {
        printf("Usage:./dir_snap <Input Directory>");
        exit(EXIT_FAILURE);
    }
    files *f = NULL;
    int n = 0;
    int snap = openFile("Snapshot.txt");
    TakeSnapshot(arcg[1], snap, arcg[1]);
    // addFile(f,"Snapshot.txt",&n);
    verifyDiff("Snapshot.txt", arcg[1]);
    return 0;
}
