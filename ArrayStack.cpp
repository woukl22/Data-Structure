#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;
}Node;

typedef struct _stack{
	int size;
	int top;
	Node* Nodes; // 힙 영역에 할당된 배열의 첫 번째 요소를 가리킨다. 
}Stack;

void create_Stack(Stack** stack, int size){
	// 스택을 힙 영역에 생성 
	(*stack) = (Stack*)malloc(sizeof(Stack));
	
	// 입력된 size만큼의 노드를 힙 영역에 생성
	(*stack)->Nodes = (Node*)malloc(sizeof(Node)*size);
	
	// size 및 top 초기화
	(*stack)->size = size;
	(*stack)->top = -1; 
}

void destroy_Stack(Stack* stack){
	// 노드 해제
	free(stack->Nodes);
	
	// 스택 해제
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
