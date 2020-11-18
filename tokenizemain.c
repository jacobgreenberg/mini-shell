#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenize.h"
#include "cat.h"

/*
 * This is my code! It's goal is to read a line from standard in and print that line to standard out
 * CS466 - Assignment 1
 * Jacob Greenberg
 */

/*
 * Purpose: retrieve line and call tokenize thereon
 * Input: line to process
 * Return: nothing, prints tokenized string to stdout
 */
int main()
{
    size_t buffer_length = BUFFER_LENGTH;
    char *input = (char *) malloc(buffer_length);

    if (!input)
    {
        perror("malloc");
        return 1;
    }

    while (1)
    {
        if (dynamic_buffer(&input, &buffer_length, stdin) == 1)
            break;

        int tokenc = get_tokens(input);
        char **tokenv = tokenize(input, &tokenc);

        if (tokenv)
        {
            int i = 0;

            while (i < tokenc && tokenv[i] != NULL)
            {
                puts(tokenv[i]);
                free(tokenv[i]);
                i++;
            }

            free(tokenv);
        }
    }

    free(input);
    return 0;
}