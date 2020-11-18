#include <stdio.h>

/*
 * This is my code! It's goal is to echo text from command line arguments, each word on a separate line
 * CS466 - Assignment 1
 * Jacob Greenberg
 */

/*
 * Purpose: echo command line arguments to the console
 * Input: command line arguments
 * Return: success (0), failure (1)
 */
int main(int argc, char *argv[])
{
    if (argc < 2) // emulate echo's behavior with a newline
    {
        printf("\n");
        return 1;
    }

    while (argc-- > 0)
        printf("%s\n", *argv++);

    return 0;
}