#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *get_command_line()
{
	char *buff = NULL;
	size_t buff_size;
	ssize_t len;

	printf("$ ");
	len = getline(&buff, &buff_size, stdin);
	//printf("%s\n", buff);
	if (buff[len - 1] == '\n') 
	{
		buff[len - 1] = '\0';
    }

	return (buff);
}

int execute (char **exe)
{
	char *buff[] = {*exe, NULL};
    if (execve(exe[0], buff, '\0') == -1)
    {
		printf("Value passed to execve = %s\n", exe[0]);
        perror("Error: ");
    }
    printf("Execution Completed Sucessfully\n");
    return (0);
}

int _tokenizer(char *str)
{
	char **arg = NULL;
	size_t ind = 0;
	char* token;
	pid_t exe_process;

	// Tokenize the input line
	token = strtok(str, " ");
	while (token != NULL) {
		arg = realloc(arg, (ind + 1) * sizeof(char *));
		if (arg == NULL) {
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		arg[ind++] = token;
		token = strtok(NULL, " ");
	}
	arg[ind] = NULL;
	if (fork() == 0)
	{
		exe_process = getpid();
		execve(str, arg, NULL);
	}
	else
	{
		wait(&exe_process);
	}
	free(str);
	free(arg);

	return 0;
}

int main (void)
{
	while (1)
	{
		_tokenizer(get_command_line());
	}
	return (0);
}