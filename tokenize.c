#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * This is my code! It's goal is to tokenize a line with delimiter " "
 * CS466 - Assignment 1
 * Jacob Greenberg
 */

/*
 * Purpose: tokenize a line with delimiter " "
 * Input: the number of tokens to process and the string to perform tokenize on
 * Return: an array of tokens (strings)
 */
char **tokenize(char *input, const int *token_count)
{
    char **tokens = (char **) malloc(*token_count * sizeof(char **));

    if (!tokens)
    {
        perror("malloc");
        exit(1);
    }

    char input_cpy[strlen(input)];
    strcpy(input_cpy, input);
    char *token = strtok(input_cpy, " ");
    int current_token = 0;

    while (current_token < *token_count && token != NULL)
    {
        tokens[current_token] = strdup(token); // copy token to array

        if (!tokens[current_token])
        {
            free(tokens);
            perror("strdup");
            exit(1);
        }

        token = strtok(NULL, " ");
        current_token++;
    }

    return tokens;
}


/*
 * Purpose: count the number of tokens in a string
 * Input: the string to process
 * Return: the number of tokens therein
 */
int get_tokens(char * string)
{
    char string_cpy[strlen(string)];
    strcpy(string_cpy, string);
    int count = 0;
    char *token = strtok(string_cpy, " ");

    while (token != NULL)
    {
        token = strtok(NULL, " ");
        count++;
    }

    return count;
}