#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include "cat.h"

/*
 * This is my code! It's goal is to read text from file and write it to another file, who's name is specified
 *                  as a command line argument
 * CS466 - Assignment 1
 * Jacob Greenberg
 */

/*
 * Purpose: take user in and print that line to file
 * Input: stdin and filename to write to
 * Return: success (0), failure (1)
 */
int main(int argc, char *argv[])
{
    char *write_file = argv[argc - 1];
    argv[argc - 1] = NULL; // remove writefile from args

    int rc = fork();

    if (rc < 0)
    {
        perror("fork");
        exit(1);
    }

    else if (rc == 0)
    {
        int fd = open(write_file, O_WRONLY | O_CREAT, 0644);
        dup2(fd, 1);
        execvp(argv[0], argv);
        close(fd);
    }

    wait(NULL);
    return 0;
}