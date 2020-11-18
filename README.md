# Assignment 1

### Program Files
* Cat: catmain.c cat.c cat.h (make catmain)
   
* Echo: echo.c (make echo)

* Tokenizer: tokenizemain.c tokenize.c tokenize.h (make tokenizemain)

* Redirect: redirect.c (make redirect)

* Shell: shellmain.c (make)

  

### Commands
* Compile shell: make
* Launch shell: ./shell



### Description

The shell contains a main loop, in which user input is collected and processed with a dynamic buffer and tokenized by the tokenize() method in tokenize.c, splitting and placing each token in an array of strings (char **) called tokenv. The first value in this array is stripped of its newline character, then run against against a series of predefined sentinel values matching possible shell commands and programs. If the first argument (tokenv[0]) matches "exit", "help", "cat", "echo", or "tok", any one of those programs will be launched in a process explained hereafter. In the case of redirect, the '>' is searched for in the second to last element of the array (tokenv[tokenc - 2]) and that process is launched in a slightly different manner than the proceeding few. Before a process is launched, the proper arguments are collected and then passed to the launch() method. Some programs like Cat and Tokenize don't take any arguments, so the program passes whitespace as the first argument and NULL as the last. for Echo and Redirect, arguments are gathered and modified by iterating over tokenv and placing those values into a new array of arguments simply called args. The method launch() is then called with two arguments: the first being the name of the executable and the second is the array of arguments necessary to that program's run, stripped of any newlines if necessary. The launch() method then spawns a child process and executes that program, while the parent waits for it's completion in order to return to the main shell. In the case of Redirect, however, its program is run in order to call another system program. Once the launch() method runs Redirect, a second child is spawned within redirect.c, going through a similar process as that in the launch() method in order to run a user specific UNIX program or command. Here, the parent process in Redirect waits for its child to complete and its parent the same. Finally, the shell frees memory from it's dynamic buffer, prints "logout", and terminates. 



### Misc.
Must use /bin/cat when doing redirection. 

```bash
/bin/cat lorem.txt > out.txt
```


### Honor Code

I did not violate the honor code in completing this assignment.