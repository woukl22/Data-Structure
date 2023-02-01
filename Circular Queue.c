#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node{
	int data;
}Node;

typedef struct _circularQueue{
	int size;
	int front;
	int rear;
	
	Node* Nodes;
}CircularQueue;

void create_Queue(CircularQueue** queue, int size){
	(*queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	(*queue)->Nodes = (Node*)malloc(sizeof(Node)*(size+1));
	(*queue)->size = size;
	(*queue)->front = 0;
	(*queue)->rear = 0;
}

void destroy_Queue(CircularQueue* queue){
	free(queue->Nodes);
	free(queue);
}

bool isFull(CircularQueue* queue){
	if(queue->front < queue->rear)
		return (queue->rear-queue->front) == queue->size;
	else
		return (queue->rear+1) == queue->front;
}

void enqueue(CircularQueue* queue, int data){
	if(isFull(queue)){
		printf("큐가 포화 상태이므로 삽입할 수 없습니다.\n");
	} else{
		int idx = queue->rear;
		if(idx == queue->size)
			queue->rear = 0;
		else
			queue->rear++;
		queue->Nodes[idx].data = data;
	}
}

bool isEmpty(CircularQueue* queue){
	return (queue->front == queue->rear);
}

int dequeue(CircularQueue* queue){
	if(isEmpty(queue)){
		printf("큐가 비어 있으므로 삭제할 수 없습니다.\n");
	} else{
		int idx = queue->front;
		if(idx == queue->size)
			queue->front = 0;
		else
			queue->front++;
		
		return queue->Nodes[idx].data;	
	}
}

int main(void){
	int i;
	CircularQueue* queue;
	create_Queue(&queue, 10);
	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);
	
	for(i = 0; i < 3; i++){
		printf("dequeue: %d, ", dequeue(queue));
		printf("front: %d, rear: %d\n", queue->front, queue->rear);
	}
	i = 100;
	while(!isFull(queue)){
		enqueue(queue, i++);
	}
	while(!isEmpty(queue)){
		printf("dequeue: %d, ", dequeue(queue));
		printf("front: %d, rear: %d\n", queue->front, queue->rear);
	}
	destroy_Queue(queue);
	
	return 0;	
}
