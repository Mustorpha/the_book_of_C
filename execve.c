#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *args[] = {"/bin/ls", "-a", "-l", NULL};
    if (execve(args[0], args, '\0') == -1)
    {
        perror("Error: ");
    }
    printf("Execution Completed Sucessfully\n");
    return (0);
}

/*if (ind == 0)
		{
			arg = malloc(sizeof(*token));
			if (arg == NULL)
			{
				free (arg);
				exit (98);
			}
			printf("Token = %s\n", token);
			**(arg + ind) = *token;
			ind++;
		}
		else
		{
			arg = realloc(arg, sizeof(*token) * (ind + 1));
			if (!arg)
			{
				free (arg);
				exit (98);
			}
			printf("Token = %s\n", token);
			**(arg + ind) = *token;
			ind++;
		}*/