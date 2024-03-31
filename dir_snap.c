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
int fileExists(const char *name)
{
    struct stat buf;
    if (stat(name, &buf) == 0)
    {
        return 1;
    }
    return 0;
}
int openFile(char *name)
{
    int snap;
    char buff[] = "Inode|FileName|Size\n";
    if (fileExists(name))
    {
        remove(name);
    }
    if ((snap = open(name, O_WRONLY | O_CREAT | O_TRUNC, S_IWUSR | S_IRUSR)) < 0)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    write(snap, buff, strlen(buff));
    return snap;
}
void writeToSnap(int fd, ino_t ino, char *filePath, off_t size)
{
    char buff[256];
    sprintf(buff, "%ju|%s|%jd\n", (uintmax_t)ino, filePath, (intmax_t)size);
    write(fd, buff, strlen(buff));
}
void TakeSnapshot(const char *nameDir, int snap)
{
    DIR *Din;
    if ((Din = opendir(nameDir)) == NULL)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    struct dirent *entry = NULL;
    while ((entry = readdir(Din)) != NULL)
    {
        char path[259];
        struct stat st;
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            sprintf(path, "%s/%s", nameDir, entry->d_name);
            printf("%s\n", path);
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
                TakeSnapshot(path, snap);
            }
        }
    }
}

int main(int arcgv, char **arcg)
{
    if (arcgv != 2)
    {
        printf("Usage:./dir_snap <Input Directory>");
        exit(EXIT_FAILURE);
    }
    int snap = openFile("Snapshot.txt");
    TakeSnapshot(arcg[1], snap);
    close(snap);
    return 0;
}
