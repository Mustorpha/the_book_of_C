#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"

extern char **environ;

char *_getenv(const char *name)
{
    int ind = 0;
    char *env_tmp, *entry;

    printf("Name received = %s\n", name);
    while (environ[ind])
    {
        env_tmp = environ[ind++];
        //printf("List searched = %s\n", env_tmp);
        entry = strtok(env_tmp, "=");
        //printf("Entries Searched = %s\n", entry);
        if (!(strcmp(name, entry)))
        {
            printf("Found a match\n");
            return (strtok(NULL, "="));
        }
    }
    return (NULL);
}

int main(int ac, char **av)
{
    char *status;
    char *path_stat;
    size_t cnt;

    if (ac != 2)
    {
        printf("Usage: %s enviroment_name...\n", av[0]);
        exit(98);
    }
    status = _getenv(av[1]);
    if (!status)
    {
        printf("Error: Invalid env name\n");
        exit(98);
    }
    if (!(strcmp(av[1], "PATH")))
    {
        path_stat = strtok(status, ":");
        for (cnt = 0; path_stat != NULL; cnt++)
        {
            printf("PATH[%lu] = %s\n", cnt, path_stat);
            path_stat = strtok(NULL, ":");
        }
    }
    else
    {
        printf("%s = %s\n", av[1], status);
    }
    return (0);
}