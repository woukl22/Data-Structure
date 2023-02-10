#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	struct _node* leftChild;
	struct _node* rightChild;
	int data;
}Node;

Node* create_Node(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	newNode->data = data;
	
	return newNode;
};

void destroy_Node(Node* node){
	free(node);
}

int main(void){
	Node* root = create_Node(10);
	root->leftChild = create_Node(20);
	root->rightChild = create_Node(30);
	root->rightChild->leftChild = create_Node(40);
	
	printf("%d\n", root->data);
	printf("%d\n", root->leftChild->data);
	printf("%d\n", root->rightChild->data);
	printf("%d\n", root->rightChild->leftChild->data);
	
	destroy_Node(root->rightChild->leftChild);
	destroy_Node(root->rightChild);
	destroy_Node(root->leftChild);
	destroy_Node(root);
	return 0;	
}
