#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int maxLength = 0;
	int maxIndex = 0;
	for (int i = 1; i < argc; i++){
		char* curr = argv[i];
		int length = strlen(curr);
		if (length > maxLength) {
			maxLength = length;
			maxIndex = i;
		}
	}
	printf("%s\n", argv[maxIndex]);
	return 0;
}
