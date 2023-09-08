#ifndef GETLINE_H
#define GETLINE_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <unistd.h>

ssize_t _getline(char **buff, size_t *buff_size, FILE *fp)
{
  const size_t INITALLOC = 16;
  const size_t ALLOCSTEP = 16;
  size_t cnt = 0;

  if ((buff == NULL) || (buff_size == NULL) || (fp == NULL))
  {
    errno = EINVAL;
    return (-1);
  }
  if (*buff == NULL)
  {
    *buff = (char *)malloc(INITALLOC);
    if (*buff == NULL)
    {
      return (-1);
    }
    else
    {
      *buff_size = INITALLOC;
    }
  }
  {
    int c;
    while ((c = getc(fp) != EOF))
    {
      /* Note we read a character. */
      cnt++;

      /* Reallocate the buffer if we need more room */
      if (cnt >= *buff_size)
      {
        size_t n_realloc = *buff_size + ALLOCSTEP;
        char * tmp = (char *)realloc(*buff, n_realloc + 1); /* +1 for the trailing NUL. */
        if (NULL != tmp)
        {
          /* Use the new buffer and note the new buffer size. */
          *buff = tmp;
          *buff_size = n_realloc;
        }
        else
        {
          /* Exit with error and let the caller free the buffer. */
          return (-1);
        }
      }

      /* Add the character to the buffer. */
      (*buff)[cnt - 1] = (char) c;

      /* Break from the loop if we hit the ending character. */
      if (c == '\n')
      {
        break;
      }
    }

    /* Note if we hit EOF. */
    if (EOF == c)
    {
      errno = 0;
      return (-1);
    }
  }

  /* Terminate the string by suffixing NUL. */
  (*buff)[cnt] = '\0';

  return (cnt);
}

#endif