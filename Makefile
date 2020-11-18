CC = gcc
CFLAGS = -Wall

all: shell catmain echo redirect tokenizemain

shell:
	$(CC) $(CFLAGS) -o shell shellmain.c tokenize.c tokenize.h cat.c cat.h

catmain: catmain.c
	$(CC) $(CFLAGS) -o catmain catmain.c cat.c cat.h

echo: echo.c
	$(CC) $(CFLAGS) -o echo echo.c

tokenizemain: tokenizemain.c
	$(CC) $(CFLAGS) -o tokenizemain tokenizemain.c tokenize.c tokenize.h cat.c cat.h

redirect: redirect.c
	$(CC) $(CFLAGS) -o redirect redirect.c cat.c cat.h

clean:
		rm -f *.o *.h.gch shell catmain echo tokenizemain redirect a.out echo *~