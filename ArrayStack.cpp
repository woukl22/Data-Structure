#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;
}Node;

typedef struct _stack{
	int size;
	int top;
	Node* Nodes; // �� ������ �Ҵ�� �迭�� ù ��° ��Ҹ� ����Ų��. 
}Stack;

void create_Stack(Stack** stack, int size){
	// ������ �� ������ ���� 
	(*stack) = (Stack*)malloc(sizeof(Stack));
	
	// �Էµ� size��ŭ�� ��带 �� ������ ����
	(*stack)->Nodes = (Node*)malloc(sizeof(Node)*size);
	
	// size �� top �ʱ�ȭ
	(*stack)->size = size;
	(*stack)->top = -1; 
}

void destroy_Stack(Stack* stack){
	// ��� ����
	free(stack->Nodes);
	
	// ���� ����
	free(stack); 
}

void push(Stack* stack, int data){
	stack->top++;
	stack->Nodes[stack->top].data = data;
}

int pop(Stack* stack){
	int topNode = stack->Nodes[stack->top].data;
	stack->top--;
	return topNode;
}

int main(void){
	Stack* stack = NULL;
	create_Stack(&stack, 10);
	
	push(stack, 3);
	push(stack, 6);
	push(stack, 9);
	push(stack, 15);

	for(int i = 0; i < 4; i++){
		printf("%d\n", pop(stack));
	}
	
	destroy_Stack(stack);

	return 0;
}
