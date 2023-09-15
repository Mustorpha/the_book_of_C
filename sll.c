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

/**
 * add_node - adds a node to the begining of a linked list
 * @head: pointer to the current head of the list
 * @str: pointer to a copy of the string element in the node
 * Return: the address of the new node
*/
list_t *add_node(list_t **head, const char *str)
{
    list_t *new;
    new  = malloc(sizeof(list_t));

    if (new == NULL)
    {
        free(new);
        return (NULL);
    }
    new->str = strdup(str);
    if (new->str == NULL)
    {
        free(new);
        return (NULL);
    }
    new->len = _strlen(str);
    new->next = *head;
    *head = new;

    return (new);
}

/**
 * free_list - frees a list_t list
 * @head: head of linked list
 */
void free_list(list_t *head)
{
	list_t *current;
	list_t *nxt;

	current = head;

	while (current != NULL)
	{
		nxt = current->next;
		free(current->str);
		free(current);
		current = nxt;
	}
}

/**
 * _strlen - finds the length of a string
 * @str: the target string
 * Return: the number of character
*/
int _strlen(const char *str)
{
    int count = 0;

    while (*str != '\0')
    {
        //printf("Started the counting\n");
        count++;
        str++;
    }

    return (count);
}

int main(int ac, char **av)
{
    char *status;
    char *path_stat;
    size_t cnt;
    list_t *head = NULL;

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
        printf("Returned back to the main function\n");
        for (cnt = 0; path_stat != NULL; cnt++)
        {
            //printf("Inside the for loop\n");
            add_node(&head, path_stat);
            //printf("PATH[%lu] = %s\n", cnt, path_stat);
            path_stat = strtok(NULL, ":");
            //printf("After the strtok second call\n");
        }
        printf("Total Paths = %lu\n", cnt);
        if (head == NULL)
        {
            printf("Head node equals NULL\n");
        }
        cnt = 0;
        while (head != NULL)
        {
            printf("Path[%lu] = %s\n", ++cnt, head->str);
            head = head->next;  
        }
        free_list(head);
    }
    else
    {
        printf("%s = %s\n", av[1], status);
    }

    return (0);
}