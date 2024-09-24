#include <stdio.h>

int main(int argc, char *argv[]) {
	
	for (int i = 1; i < argc ; i++) {
		for (char *p = argv[i]; *p != '\0'; p++) {
			if (*p < 'a' || *p > 'z') { 
				printf("Invalid input: %c", *p);
				return 1;
			}
		}
		printf("%s \t", argv[i]);
	}

}
