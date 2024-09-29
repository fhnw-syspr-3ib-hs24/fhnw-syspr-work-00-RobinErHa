#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	struct node* left;
	struct node* right;
	char label[32];
} Node;

int main() {	
	Node *n1 = malloc(sizeof(Node));
	Node *n2 = malloc(sizeof(Node));
	Node *n3 = malloc(sizeof(Node));
	
	// only space for 31 characters in the 32Byte char Array 
	// -> There needs to be one Byte for the esc. Sequence '\0' which strcpy appends automatically
	strcpy(n1->label, "I'm the top node.");
	n1->left = n2;
	n1->right = n3;


	strcpy(n2->label, "I'm the left node.");
	strcpy(n3->label, "I'm the right node");

	printf("top: %s\n", n1->label);
	printf("left: %s\n", n1->left->label);
	printf("right: %s\n", n1->right->label);

	free(n1);
	free(n2);
	free(n3);

	return 0;
}
