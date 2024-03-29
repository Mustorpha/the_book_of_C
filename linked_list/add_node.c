#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

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