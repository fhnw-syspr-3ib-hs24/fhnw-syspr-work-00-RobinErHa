CC=gcc 
CFLAGS=-std=c99 -pedantic -pedantic-errors -Werror -Wall -Wextra

all: args sizeof tree

args: args.c
sizeof: sizeof.c
tree: tree.c
my_copy: my_copy.c

clean:
	rm -f args
	rm -f sizeof
	rm -f tree


