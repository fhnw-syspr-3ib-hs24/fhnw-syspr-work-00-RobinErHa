#include <stdio.h>

	typedef struct node {
		struct node* left;
		struct node* right;
		char* label;
	} Node;

int main(int argc, char *argv[]) {	
	Node *n1 = malloc(sizeof(Node));

	return 0;
}
