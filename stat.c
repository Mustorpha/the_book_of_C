#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main (int ac, char *av[])
{
    int ind = 1;
    struct stat st;

    if (ac < 2)
    {
        printf("Usage: ./%s path_to_file...", av[0]);
    }

    while(av[ind])
    {
        printf("File %s: ", av[ind++]);
        if (stat(av[ind], &st) == 0)
        {
            printf("FOUND\n");
        }
        else
        {
            printf("NOT FOUND\n");
        }
    }

    return (0);
}