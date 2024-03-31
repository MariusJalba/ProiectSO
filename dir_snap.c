#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
void parcurgere(const char *nameDir)
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
        struct stat buf;
        if (strcmp(entry->d_name, ".") !=0 && strcmp(entry->d_name, "..")!=0)
        {
            sprintf(path, "%s/%s", nameDir, entry->d_name);
            printf("Relative path: %s\n", path);
            if (stat(path, &buf) != 0)
            {
                perror("stat");
                exit(EXIT_FAILURE);
            }
            if(S_ISDIR(buf.st_mode))
            {
                parcurgere(path);
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
    parcurgere(arcg[1]);
    return 0;
}