#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cat.h"

/*
 * This is my code! It's goal is to dynamically allocate buffer based on size of stdin
 * CS466 - Assignment 1
 * Jacob Greenberg
 */

/*
 * Purpose: dynamically allocate buffer based on size of stdin
 * Input: pointer to buffer, pointer to buffer length, pointer to input
 * Return: success (0), failure (1)
 */
int dynamic_buffer(char **line, size_t *buffer_length, void *input)
{
    if (fgets(*line, *buffer_length, input) == NULL)
        return 1;

    size_t curr_len = strlen(*line);

    while (strchr(*line, '\n') == NULL) // while EOF not reached
    {
        *buffer_length += BUFFER_LENGTH;
        *line = realloc(*line, *buffer_length);

        if (!*line)
        {
            perror("realloc");
            exit(1);
        }

        if (fgets(*line + curr_len,  (int) (*buffer_length - curr_len), input) == NULL)
            return 0;

        curr_len += strlen(*line + curr_len);
    }

    return 0;
}