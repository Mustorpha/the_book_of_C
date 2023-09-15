// C program for splitting a string
// using strtok()
#include <stdio.h>
#include <string.h>

int main()
{
	char *str = "Just crazy bucks";

	// Returns first token
	char* token = strtok(str, " ");

	// Keep printing tokens while one of the
	// delimiters present in str[].
	while (token != NULL) {
		printf(" %s\n", token);
		token = strtok(NULL, " ");
	}

	return 0;
}
