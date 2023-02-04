#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node{
	int data;
	struct _node* nextNode;
}Node;

typedef struct _linkedQueue{
	Node* front;
	Node* rear;
	int size;
}LinkedQueue;

void create_Queue(LinkedQueue** queue){
	(*queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
	(*queue)->size = 0;
}

Node* create_Node(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;

    return newNode;
}

void destroy_Node(Node* node){
    free(node);
}

void enqueue(LinkedQueue* queue, int data){
	Node* newNode = create_Node(data);
	if(queue->front == NULL){
		queue->front = newNode;
	} else{
		queue->rear->nextNode = newNode;
	}
	queue->rear = newNode;
	queue->size++;
}

int dequeue(LinkedQueue* queue){
	Node* delNode = queue->front;
	int delNodeData = delNode->data;
	if(delNode->nextNode == NULL){
		queue->front = NULL;
		queue->rear = NULL;
	} else{
		queue->front = queue->front->nextNode;
	}
	destroy_Node(delNode);
	queue->size--;
	
	return delNodeData;
}

bool isEmpty(LinkedQueue* queue){
	return (queue->front == NULL);
}

void destroy_Queue(LinkedQueue* queue){
	while(!isEmpty(queue)){
		dequeue(queue);
	}
	free(queue);
}

int main(void){
	int i;
	LinkedQueue* queue;
	create_Queue(&queue);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
		
	while(!isEmpty(queue)){
		printf("dequeue: %d, ", dequeue(queue));
		printf("front: %d, rear: %d\n", queue->front ? queue->front->data : 0, queue->rear ? queue->rear->data : 0);
	}
	
	destroy_Queue(queue);
	
	return 0;	
}
