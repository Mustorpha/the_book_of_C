#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

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
	char **arg;
	size_t ind = 0, word_count = 0;
	char* token;

	/*for (ind  = 0; str[ind] != '\0'; ind++)
	{
		if (str[ind - 1] == ' ')
		{
			word_count++;
		}
	}
	ind = 0;
	printf("Word count = %lu\n", (word_count + 1));
	arg = malloc(sizeof(char) * (word_count));
	if (!arg)
	{
		free(arg);
		exit(98);
	}*/
	token = strtok(str, " ");
	while (token != NULL)
	{
		if (ind == 0)
		{
			arg = malloc(sizeof(char));
			if (arg == NULL)
			{
				printf("Malloc Failed\n");
				free (arg);
				exit (98);
			}
			arg[ind] = token;
			printf("Tokenm = %s\n", arg[ind]);
			token = (strtok(NULL, " "));
			ind++;
		}
		else
		{
			arg = realloc(arg, sizeof(char)*(ind + 1));
			if (!arg)
			{
				printf("Realloc Failed\n");
				free (arg);
				exit (98);
			}
			arg[ind] = token;
			printf("Tokenr = %s\n", arg[ind]);
			token = (strtok(NULL, "   "));
			ind++;
		}
		/**(arg + ind) = token;
		printf("assignment ran\n");
		printf("[%lu] contains %s\n", ind, *(arg + ind));
		ind++;
		token = (strtok(NULL, " "));*/
	}
	//arg[ind] = '\0';
	word_count = 0;
	while (arg[word_count])
	{
		printf("Value = %s\n", arg[word_count]);
		word_count++;
	}
	printf("Number of element = %lu\n", word_count);
	execute(arg);
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