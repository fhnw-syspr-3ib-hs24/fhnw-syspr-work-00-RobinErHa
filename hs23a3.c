#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node { int key; char value[32]; struct node* next; };
struct node *list = NULL;

struct node *add(struct node *list, int key, char *value);
struct node *get(struct node *list, int key);

int main() {
	list = add(list, 3000, "Bern");
	list = add(list, 4000, "Basel");
	list = add(list, 8000, "Zurich");
	struct node *n = get(list, 4000);
	printf("%d: %s\n", n->key, n->value);
}

struct node *add(struct node *list, int key, char *value){
	struct node *n = malloc(sizeof(struct node));
	n->key = key;
	strcpy(n->value, value);

	struct node *t = list + 1;
	n->next = list;
	return n;
}


struct node *get(struct node *list, int key){
	struct node *n = list;
	while (n != NULL && key != n->key) {
		n = n->next;
	}
	return n;
}

