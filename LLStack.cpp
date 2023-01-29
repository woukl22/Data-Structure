#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node* nextNode;
}Node;

typedef struct _stack{
    Node* list;
    Node* top;
}Stack;

void create_Stack(Stack** stack){
    (*stack) = (Stack*)malloc(sizeof(Stack));
    (*stack)->list = NULL;  // 데이터를 담는 연결 리스트 
    (*stack)->top = NULL;   // 연결 리스트의 테일을 가리킴 
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

void push(Stack* stack, int data){
    Node* newNode = create_Node(data);
    if(stack->list == NULL){
        stack->list = newNode;
    } else{
        stack->top->nextNode = newNode;
    }
    stack->top = newNode;
}

int pop(Stack* stack){
    int topNode = stack->top->data;
    
    if(stack->list == stack->top){
    	if(stack->list != NULL)
        	destroy_Node(stack->top);
        stack->list = NULL;
        stack->top = NULL;
    } else{
        Node* currentTop = stack->list;
        while(currentTop != NULL && currentTop->nextNode != stack->top){
            currentTop = currentTop->nextNode;
        }

        destroy_Node(currentTop->nextNode);
        stack->top = currentTop;
        stack->top->nextNode = NULL;
    }
    return topNode;
}

void destroy_Stack(Stack* stack){
    while(stack->list != NULL){
        pop(stack);
    }
    free(stack);
}

int main(void){
    Stack* stack = NULL;
    create_Stack(&stack);
   	
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
