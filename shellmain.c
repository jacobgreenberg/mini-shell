#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "tokenize.h"
#include "cat.h"
#define HELP "help"
#define EXIT "exit"
#define CAT "cat"
#define ECHO "echo"
#define TOKENIZE "tok"
#define REDIRECT ">"
#define EXEC_CAT "./catmain"
#define EXEC_ECHO "./echo"
#define EXEC_TOKENIZE "./tokenizemain"
#define EXEC_REDIRECT "./redirect"

/*
 * This is my code! It's goal is to run the shell, maintain processes, and execute cat, echo, tokenize, and redirect
 * CS466 - Assignment 1
 * Jacob Greenberg
 */

/*
 * Purpose: print help/usage menu to console
 * Input: nothing
 * Return: nothing
 */
void help()
{
    printf("\nShell Help:\n\n"
           "cat : prints input from standard input to standard output\n"
           "echo: displays a line of text (echo Hello World!)\n"
           "tok : splits tokens among line of text and prints them to standard output\n"
           ">   : file redirection (ls -l > output.txt)\n"
           "exit: logs user out of shell\n\n");
}


/*
 * Purpose: create child process and launch program
 * Input: program name and its respective arguments
 * Return: nothing
 */
void launch(char *program, char **args)
{
    int rc = fork();

    if (rc < 0)
    {
        perror("fork");
        exit(1);
    }

    else if (rc == 0)
    {
        if (execvp(program, args) == -1)
        {
            perror("execvp");
            exit(1);
        }
    }

    wait(NULL);
}


/*
 * Purpose: strip newline character from end of string
 * Input: the string
 * Return: newline-less string
 */
char * rm_newline(char *string)
{
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';

    return string;
}


/*
 * Purpose: main shell loop, call launch on programs based on user in
 * Input: stdin
 * Return: success (0), failure (1)
 */
int main()
{
    size_t buffer_length = BUFFER_LENGTH;
    char *input = (char *) malloc(buffer_length);

    while (1)
    {
        printf("?> "); // shell line

        if (dynamic_buffer(&input, &buffer_length, stdin) == 1)
            break;

        int tokenc = get_tokens(input);
        char **tokenv = tokenize(input, &tokenc);
        tokenv[0] = rm_newline(tokenv[0]);

        // sentinel
        if (tokenc < 2 && ((strcmp(tokenv[0], EXIT) != 0) && (strcmp(tokenv[0], HELP) != 0) &&
            (strcmp(tokenv[0], CAT) != 0) && (strcmp(tokenv[0], ECHO) != 0) && (strcmp(tokenv[0], TOKENIZE) != 0)))
            continue;

        else if (strcmp(tokenv[0], EXIT) == 0)
            break;

        else if (strcmp(tokenv[0], HELP) == 0)
            help();

        else if (strcmp(tokenv[0], CAT) == 0)
        {
            char *args[] = {"", NULL};
            launch(EXEC_CAT, args);
        }

        else if (strcmp(tokenv[0], ECHO) == 0 && tokenc >= 2)
        {
                char *args[tokenc];
                args[tokenc] = NULL;

                for (int i = 0; i < tokenc; i++)
                    args[i] = tokenv[i];

                launch(EXEC_ECHO, args);
        }

        else if (strcmp(tokenv[0], TOKENIZE) == 0)
        {
            char *args[] = {"", NULL};
            launch(EXEC_TOKENIZE, args);
        }

        else if (strcmp(tokenv[tokenc - 2], REDIRECT) == 0)
        {
            if (tokenc < 3) // at minimum 3 args including >
            {
                fprintf(stderr, "Insufficient arguments for redirection\n");
                exit(1);
            }

            char *args[tokenc - 1]; // -1 because > not included
            args[tokenc - 1] = NULL;

            for (int i = 0; i < tokenc - 1; i++)
                args[i] = tokenv[i];

            args[tokenc - 2] = rm_newline(tokenv[tokenc - 1]); // last arg is writefile name
            launch(EXEC_REDIRECT, args);
        }
        
            free(tokenv);
    } // end of loop

    free(input);
    printf("logout\n");
    return 0;
}
