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
				printf("중복된 값은 삽입할 수 없습니다.\n");
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
		printf("트리가 비어 있어 삭제할 수 없습니다.\n");
	} else {
		Node* del = NULL;
		Node* parent = NULL;
		Node* child = NULL;
		
		// 삭제할 노드 탐색 
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
			printf("해당 노드가 존재하지 않아, 삭제할 수 없습니다.\n");
			return;
		}
		
		if(!del->leftChild && !del->rightChild){
			printf("case 1: %d\n", del->data);
		// case 1: 삭제할 노드의 차수가 0인 경우 
			if(parent){ // 부모가 있는 경우 
				if(parent->leftChild == del) parent->leftChild = NULL;
				else if(parent->rightChild == del) parent->rightChild = NULL;
			} else{	// 부모가 없는 경우(루트 노드) 
				*root = NULL;
			} 
		} else if(!del->leftChild || !del->rightChild){
			printf("case 2: %d\n", del->data);
		// case 2: 삭제할 노드의 차수가 1인 경우 
			Node* child;
			if(del->leftChild) child = del->leftChild;
			else if(del->rightChild) child = del->rightChild;
			
			if(parent){	// 부모가 있는 경우 
				if(parent->leftChild == del) parent->leftChild = child;
				else if(parent->rightChild == del) parent->rightChild = child;
			} else{	// 부모가 없는 경우(루트 노드) 
				*root = child;
			}
		} else if(del->leftChild && del->rightChild){
			printf("case 3: %d\n", del->data);
		// case 3: 삭제할 노드의 차수가 2인 경우
			Node* successor = del->rightChild;
			Node* sParent = del;	// successor의 부모
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
