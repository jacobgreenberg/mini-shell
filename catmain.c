#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cat.h"

/*
 * This is my code! It's goal is to read a line from standard in and print that line to standard out
 * CS466 - Assignment 1
 * Jacob Greenberg
 */

/*
 * Purpose: read a line from stdin, print that line to stdout
 * Input: stdin
 * Return: success (0), failure (1)
 */
int main()
{
    size_t buffer_length = BUFFER_LENGTH;
    char *line = (char *) malloc(buffer_length);

    if (!line)
    {
        perror("malloc");
        return 1;
    }

    while (dynamic_buffer(&line, &buffer_length, stdin) != 1)
        puts(line);

    free(line);
    return 0;
}
