CC=gcc
CFLAGS=-std=c11 -pedantic -Wall -Werror -Wextra
SANFLAG=#-fsanitize=address -g
BUILDPATH=../build/

PLOTTERNAME=Plotter.out

all: graph.o stack.o calc.o check_string.o polish_notation.o print.o
	$(CC) $(CFLAGS) graph.o stack.o calc.o check_string.o polish_notation.o print.o -o $(BUILDPATH)$(PLOTTERNAME)

start:
	$(BUILDPATH)$(PLOTTERNAME)

graph.o:
	$(CC) $(CFLAGS) -c graph.c

stack.o:
	$(CC) $(CFLAGS) -c stack.c

calc.o:
	$(CC) $(CFLAGS) -c calc.c

check_string.o:
	$(CC) $(CFLAGS) -c check_string.c

polish_notation.o:
	$(CC) $(CFLAGS) -c polish_notation.c

print.o:
	$(CC) $(CFLAGS) -c print.c

clang:
	clang-format -i *.c *.h

clean:
	rm -rf *.o $(BUILDPATH)$(PLOTTERNAME)

rebuild: clean all