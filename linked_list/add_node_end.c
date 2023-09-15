#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/**
 * add_node - adds a node to the begining of a linked list
 * @head: pointer to the current head of the list
 * @str: pointer to a copy of the string element in the node
 * Return: the address of the new node
*/
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new;
    list_t *current = *head;
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
    new->next = NULL;
    
    while (current)
    {
        if (current->next == NULL)
        {
            current->next = new;
            break;
        }

        current = current->next;
    }

    return (new);
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
        printf("Started the counting\n");
        count++;
        str++;
    }

    return (count);
}