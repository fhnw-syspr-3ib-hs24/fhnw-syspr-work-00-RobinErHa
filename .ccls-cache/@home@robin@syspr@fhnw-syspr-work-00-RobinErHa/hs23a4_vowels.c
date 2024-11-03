#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	for(int k =1; k < argc; k++) {
		int a = 0;
		int e = 0;
		int i = 0;
		int o = 0;
		int u = 0;

		char* curr = argv[k]; //charpointer to the word at argv[k] -> so the first char of the word
		for(int j = 0; j < strlen(curr); j++){
			char *c = curr + j;		//charpointer to memory adress of the char in current word
			if (*c == 'a') a++;		//dereferencing the charpointer to get the char value to compare
			else if (*c == 'e') e++;
			else if (*c == 'i') i++;
			else if (*c == 'o') o++;
			else if (*c == 'u') u++;
		}
		printf("a: %i, e: %i, i: %i, o: %i, u: %i \n", a, e, i, o, u);
	}
	return 0;
}
