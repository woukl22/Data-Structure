#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
	struct _node* leftChild;
	struct _node* rightChild;
	int data;
}Node;

typedef struct BinarySearchTree{
	Node* root;
}BST;

Node* create_Node(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	newNode->data = data;
	
	return newNode;
}

void destroy_Node(Node* node){
	free(node);
}

void create_BST(BST** bst){
	(*bst) = (BST*)malloc(sizeof(BST));
	(*bst)->root = NULL;
}

void insert_Node(Node** root, int data){
	if(!(*root)){
		*root = create_Node(data);
		return;
	} else{
		Node* currentNode = *root;
		while(currentNode){
			if(currentNode->data == data){
				printf("�ߺ��� ���� ������ �� �����ϴ�.\n");
				return;
			} else if(currentNode->data > data){
				if(currentNode->leftChild){
					currentNode = currentNode->leftChild;
				} else{
					currentNode->leftChild = create_Node(data);
					return;
				}
			} else if(currentNode->data < data){
				if(currentNode->rightChild){
					currentNode = currentNode->rightChild;	
				} else{
					currentNode->rightChild = create_Node(data);
					return;
				}
			}
		}
	}
}

void delete_Node(Node** root, int data){
	if(!root){
		printf("Ʈ���� ��� �־� ������ �� �����ϴ�.\n");
	} else {
		Node* del = NULL;
		Node* parent = NULL;
		Node* child = NULL;
		
		// ������ ��� Ž�� 
		del = *root;
		while(del){
			if(del->data == data)
				break;
			parent = del;
			if(del->data > data)
				del = del->leftChild;
			else
				del = del->rightChild;
		}
		
		if(!del){
			printf("�ش� ��尡 �������� �ʾ�, ������ �� �����ϴ�.\n");
			return;
		}
		
		if(!del->leftChild && !del->rightChild){
			printf("case 1: %d\n", del->data);
		// case 1: ������ ����� ������ 0�� ��� 
			if(parent){ // �θ� �ִ� ��� 
				if(parent->leftChild == del) parent->leftChild = NULL;
				else if(parent->rightChild == del) parent->rightChild = NULL;
			} else{	// �θ� ���� ���(��Ʈ ���) 
				*root = NULL;
			} 
		} else if(!del->leftChild || !del->rightChild){
			printf("case 2: %d\n", del->data);
		// case 2: ������ ����� ������ 1�� ��� 
			Node* child;
			if(del->leftChild) child = del->leftChild;
			else if(del->rightChild) child = del->rightChild;
			
			if(parent){	// �θ� �ִ� ��� 
				if(parent->leftChild == del) parent->leftChild = child;
				else if(parent->rightChild == del) parent->rightChild = child;
			} else{	// �θ� ���� ���(��Ʈ ���) 
				*root = child;
			}
		} else if(del->leftChild && del->rightChild){
			printf("case 3: %d\n", del->data);
		// case 3: ������ ����� ������ 2�� ���
			Node* successor = del->rightChild;
			Node* sParent = del;	// successor�� �θ�
			while(successor->leftChild){
				sParent = successor;
				successor = successor->leftChild;
			}
			del->data = successor->data;
			if(sParent->leftChild == successor)
				sParent->leftChild = successor->rightChild;
			else if(sParent->rightChild == successor)
				sParent->rightChild = successor->rightChild;
			del = successor;
		}
		destroy_Node(del);
	}
}

void inorder(Node* root){
	if(root){
		if(root->leftChild) inorder(root->leftChild);
		printf("%d ", root->data);
		if(root->rightChild) inorder(root->rightChild);	
	}
}

void destroy_BST(BST* bst){
	while(bst->root){
		delete_Node(&bst->root, bst->root->data);
	}
	free(bst);
}

int main(void){
	BST* bst;
	create_BST(&bst);
	
	delete_Node(&bst->root, 7);
	insert_Node(&bst->root, 7);
	insert_Node(&bst->root, 32);
	insert_Node(&bst->root, 3);
	insert_Node(&bst->root, 21);
	insert_Node(&bst->root, 16);
	insert_Node(&bst->root, 5);
	insert_Node(&bst->root, 6);
	insert_Node(&bst->root, 17);
	inorder(bst->root);
	printf("\n"); 
	
	delete_Node(&bst->root, 8);
	inorder(bst->root);
	printf("\n");
	
	delete_Node(&bst->root, 20);
	inorder(bst->root);
	printf("\n");
	
	delete_Node(&bst->root, 5);
	inorder(bst->root);
	printf("\n");

	delete_Node(&bst->root, 7);
	inorder(bst->root);
	printf("\n");
	
	destroy_BST(bst);
	
	
	return 0;
}
