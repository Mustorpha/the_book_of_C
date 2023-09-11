#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t get_command_line()
{
	char *buff = NULL;
	size_t buff_size;
	ssize_t char_size;

	printf("$ ");
	char_size = getline(&buff, &buff_size, stdin);
	printf("%s\n", buff);
	free(buff);

	return (char_size);
}

int main (void)
{
	while (1)
	{
		/* code */
		ssize_t len = get_command_line();
		printf("Total character read = %lu\n", len);
	}
	return (0);
}