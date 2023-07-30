#include <stdio.h>
#include "main.h"

/**
 * main - test the sum_of_multiples functions
 * 
 * Return: void
*/

int main (void)
{
  int result;

  printf("Enter the number limit: ");
  scanf("%d", &result);
  result = (sum_of_multiples(result));
  printf("%d", result);
}

/**
 * sum_of_multiples - finds the sum all multiples of a number
 * @number: the search limit
 * 
 * Description: This is a function that search for all multiples of
 * 3 and 5 below a given number and sum them up
 * Return: the total
*/

int sum_of_multiples(int number)
{
  int total;
  int i;

  total = 0;
  
  for (i=0; i < number; i++)
  {
    if (i%3 == 0 || i%5 == 0)
    {
      total = total + i;
    }
  }
    return total;
}