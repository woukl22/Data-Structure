#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;
	struct _node* nextNode;
}Node;


Node* create_Node(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->nextNode = NULL;
	
	return newNode;	
}

void destroy_Node(Node* node){
	free(node);
}


void append_Node(Node** head, int data){
	Node* newNode = create_Node(data);
	if(*head == NULL){
		*head = newNode;
	} else{
		Node* currentNode = *head;
		while(currentNode->nextNode != NULL){
			currentNode = currentNode->nextNode;
		}
		currentNode->nextNode = newNode;
	}
}

Node* find_Node(Node* head, int location){
	Node* currentNode = head;
	while(currentNode != NULL && (--location) > 0){
		currentNode = currentNode->nextNode;
	}
	if(location > 0){
		printf("해당 위치에 노드가 존재하지 않아, 헤드 노드를 반환합니다.\n");
		return head;
	}
	return currentNode;
}

void remove_Node(Node** head, Node* removeNode){
	if(*head == removeNode){
		*head = removeNode->nextNode;
		destroy_Node(removeNode);
	} else{
		Node* currentNode = *head;
		while(currentNode != NULL && currentNode->nextNode != removeNode){
			currentNode = currentNode->nextNode;
		}
		if(currentNode != NULL){
			currentNode->nextNode = removeNode->nextNode;	
			destroy_Node(removeNode);
		}
	}
}

void insertNext_Node(Node* currentNode, int data){
	Node* newNode = create_Node(data);
	newNode->nextNode = currentNode->nextNode;
	currentNode->nextNode = newNode;
}

int num_Node(Node* head){
	int num = 0;
	while(head != NULL){
		head = head->nextNode;
		num++;
	}
	return num;
}

void print_List(Node* head){
	Node* currentNode = head;
	while(currentNode != NULL){
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	}
	printf("\n");
}


int main(void){
	Node* list = NULL;
	append_Node(&list, 0);
	append_Node(&list, 1);
	append_Node(&list, 2);
	append_Node(&list, 3);
	Node* find = find_Node(list, 2);
	remove_Node(&list, find);
	print_List(list);	
	find = find_Node(list, 7);
	print_List(list);	
	remove_Node(&list, find);
	print_List(list);	
	insertNext_Node(find, 5);
	print_List(list);	
	find = find_Node(list, 2);
	print_List(list);	
	int num = num_Node(list);
	printf("리스트의 길이는 %d 입니다.\n", num);
	print_List(list);	
	
	
	while(num_Node != 0){
		remove_Node(&list, 0);
	}
	destroy_Node(list);
	return 0;	
}
