#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    char *buff = NULL;
    size_t buff_siz;
    ssize_t len;
    int ind = 0;

    len = getline(&buff, &buff_siz, stdin);
    printf("The total character read = %lu\n", len);
    printf("The buffer size = %lu\n", buff_siz);
    
    while (buff[ind] != '\0')
    {
        printf("The value[%d] = %c\n", ind, buff[ind]);
        ind++;
    }
    free(buff);

    return (0);
}