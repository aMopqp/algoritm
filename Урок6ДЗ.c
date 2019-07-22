#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct NodeS {
	char data[10];
	struct NodeS *next;
} NodeS;

typedef struct {
	NodeS *head;
	int size;
} StackS;

typedef struct NodeTree {
	int data;
	struct NodeTree *left;
	struct NodeTree *right;
	struct NodeTree *parent;
} NodeTree;

void preOrderTravers(NodeTree* root) {
	if (root) {
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void preOrderTravers2(NodeTree* root) {
	if (root) {
		preOrderTravers(root->left);
		printf("%d ", root->data);
		preOrderTravers(root->right);
	}
}

void preOrderTravers3(NodeTree* root) {
	if (root) {
		preOrderTravers(root->left);
		preOrderTravers(root->right);
		printf("%d ", root->data);
	}
}

NodeTree* SeekpreOrderTravers(NodeTree* root , int z ) {
	if (root) {
		if (root->data == z) return root;
		else if (root->data > z)
			return SeekpreOrderTravers(root->left, z);
		else
			return SeekpreOrderTravers(root->right, z);
	}
	return NULL;
}

NodeTree* InsertpreOrderTravers(NodeTree* root, int z, NodeTree* parent) {
	if (root) {
		if (root->data == z) return root;
		else if (root->data > z)
			return InsertpreOrderTravers(root->left, z, root);
		else
			return InsertpreOrderTravers(root->right, z, root);
	}
	NodeTree *temp = (NodeTree*)malloc(sizeof(NodeTree));
	if (temp == NULL) return 0;
	return NULL;

	temp->parent = root;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = z;
	if (z < parent->data) parent->left = temp;
	else parent->right = temp;
	return temp;
}

int pushS(StackS *st, char val[10]) {
	NodeS *temp = (NodeS*)malloc(sizeof(NodeS));
	if (temp == NULL) return 0;
	for(int i =0 ; i<10; i++)
	  temp->data[i] = val[i];

	temp->next = st->head;

	st->head = temp;
	st->size++;
	return 1;
}

char* popS(StackS *st) {
	if (st->size == 0) {
		return "\0";
	}
	char result[10];
	NodeS *temp = st->head;
	for(int i =0; i<10 ; i++)
	result[i] = st->head->data[i];

	st->head = st->head->next;
	st->size--;
	free(temp);
	return result;
}

int HashFunc(char *a)
{
	int s=0;
	char i = 0;
	while (i<10)
	{
		s += a[i++];
	}
	return s%50;
}

int main(int argc, const char** argv) {
	char String[50][10];
	StackS HashARR[50];
	for (int i = 0; i < 50; i++)
	{
		HashARR[i].head = NULL;
		HashARR[i].size = 0;
	}
	for (char i = 0; i < 50; i++)
		for (char j = 0; j < 10; j++)
			String[i][j] = i + j+31;

	for (int i = 0; i < 50; i++)
	{
		pushS(&HashARR[HashFunc(String[i])], String[i]);
	}
	for (int i=0; i<50; i++)
	{
		while (HashARR[i].size > 0) {
			printf("%s ", popS(&HashARR[i]));
		}
		printf("\n");
		}
	return 0;
