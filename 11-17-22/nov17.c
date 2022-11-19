#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char* val;
	struct node* left;
	struct node* right;
} node;

char* serialize();
node* deserialize();
void setNodeVal();
node* createNode();
void freeTree();
int main() {
	puts("start");

	node* root = calloc(1, sizeof(node));
	
	// build tree with help from user
	puts("Please enter a string representation of the tree.");
	puts("\nEx:\n\t[root,[sam,,],[ben,[mike,,],]");

	freeTree(root);
	puts("end");
	return 0;
}
char* serialize(node* root);
node* deserialize(char* str) {
}
void setNodeVal(node* n, char* val) {
	n->val = malloc(strlen(val) + 1);
	strcpy(n->val, val);
}
node* createNode(char* val) {
	node* newNode = calloc(1, sizeof(node));
	setNodeVal(newNode, val);
	return newNode;
}
void freeTree(node* root) {
	if (root->left != NULL) {
		freeTree(root->left);
		free(root->left);
	}
	if (root->right != NULL) {
		freeTree(root->right);
		free(root->right);
	}
	if (root->val != NULL) free(root->val);
}
