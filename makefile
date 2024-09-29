CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: args sizeof tree

args: args.c
sizeof: sizeof.c
tree: tree.c

clean:
	rm -f args
	rm -f sizeof
	rm -f tree


