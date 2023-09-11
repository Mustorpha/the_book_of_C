#include <stdio.h>
#include "lists.h"

/**
 * list_len - finds the number of elements in a linked list
 * @h: the head of the linked list
 * Return: the number of element in the linked list
*/
size_t list_len(const list_t *h)
{
    size_t element_count = 0;

    while (h)
    {
        element_count++;
        h = h -> next;
    }

    return (element_count);
}