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
		Node* tail = *head;
		while(tail->nextNode != NULL){
			tail = tail->nextNode;
		}
		tail->nextNode = newNode;
	}
}

Node* find_Node(Node* head, int location){
	Node* currentNode = head;
	while(currentNode != NULL && (--location) >= 0){
		currentNode = currentNode->nextNode;
	}
	if(location >= 0){
		printf("Not found");
	}
	return currentNode;
}

void remove_Node(Node* head, Node* removeNode){
	Node* currentNode = head;
	while(currentNode != NULL && currentNode->nextNode != removeNode){
		currentNode = currentNode->nextNode;	
	}
	if(currentNode != NULL){
		currentNode->nextNode = removeNode->nextNode;	
	}
	destroy_Node(removeNode);
}

void insertAfter_Node(Node* currentNode, int data){
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

int findData_Node(Node* head, int location){
	Node* currentNode = head;
	while(location > 0){
		currentNode = currentNode->nextNode;
		location--;
	}
	return currentNode->data;
}

void print_List(Node* head){
	Node* currentNode = head;
	while(currentNode != NULL){
		printf("%d ", currentNode->data);
		currentNode = currentNode->nextNode;
	}
}

int main(void){
	Node* list = NULL;
	append_Node(&list, 0);
	append_Node(&list, 1);
	append_Node(&list, 2);
	append_Node(&list, 3);
	Node* find = find_Node(list, 2);
	remove_Node(list, find);
	find = find_Node(list, 1);
	insertAfter_Node(find, 5);
	find = find_Node(list, 2);
	int num = num_Node(list);
	printf("리스트의 크기는 %d 입니다.\n", num);
	int idx = findData_Node(list, 2);
	printf("2번 인덱스에 들어있는 값은 %d 입니다.\n", idx);
	printf("리스트에 있는 값은 다음과 같습니다: ");
	print_List(list);
	
	while(num_Node != 0){
		remove_Node(list, 0);
	}
	destroy_Node(list);
	return 0;	
}






