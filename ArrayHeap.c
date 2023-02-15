#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct _node{
	int data;
}Node;

typedef struct _heap{
	Node* Nodes;
	int size;
	int max;
}Heap;

Node* create_Node(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	return newNode;
}

void destroy_Node(Node* node){
	free(node);
}

Heap* create_Heap(int max){
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->Nodes = (Node*)malloc(sizeof(Node)*(max+1));
	heap->size = 0;
	heap->max = max;
	return heap;
}

void destroy_Heap(Heap* heap){
	free(heap->Nodes);
	free(heap);
}

void insert_Heap(Heap* heap, int data){
	if(heap->size == heap->max){
		printf("더 이상 삽입할 수 없습니다.\n");
	} else{
		heap->size++;
		Node* nodes = heap->Nodes;
		int idx = heap->size;
		nodes[idx].data = data;
		while(idx > 1 && nodes[idx].data > nodes[idx/2].data){
			int temp = nodes[idx].data;
			nodes[idx].data = nodes[idx/2].data;
			nodes[idx/2].data = temp;
			idx/=2;
		}
		// 힙 사이즈 ++
		// 인덱스 = 힙 사이즈
		// 부모 노드와 비교해서 부모 노드의 우선순위보다 크면 위치 교환 
	}
}

int delete_Heap(Heap* heap){
	if(heap->size == 0){
		printf("더 이상 삭제할 수 없습니다. 0이 반환됩니다. ");
		return 0;
	} else{	
		Node* nodes = heap->Nodes;
		
		int first = nodes[1].data;
		nodes[1].data = nodes[heap->size--].data;
		
		int parent = 1;
		int child = 2;
		
		while(child < heap->size){
			if(child+1 <= heap->size && nodes[child].data < nodes[child+1].data)
				child = child+1;
			
			if(nodes[child].data > nodes[parent].data){
				int temp = nodes[child].data;
				nodes[child].data = nodes[parent].data;
				nodes[parent].data = temp;
				
				parent = child;
				child *= 2;
			}
		}
		// 자식 노드가 있어야 함
		// 자식 노드 중에서 왼쪽이 큰지, 오른쪽이 큰지 
		// 자식 노드와 비교해서 부모 노드가 더 작으면 위치 교환 
		return first;
	}
}

void print_Heap(Heap* heap){
	int i;
	printf("Heap: ");
	for(i = 1; i <= heap->size; i++){
		printf("%d ", heap->Nodes[i].data);
	}
	printf("\n");
}

void delete_all(Heap* heap){
	int i;
	int size = heap->size;
	printf("Delete: ");
	for(i = 1; i <= size; i++){
		printf("%d ", delete_Heap(heap));
	}
	printf("\n");
} 


int main(void){
	Heap* heap = create_Heap(MAX);
	insert_Heap(heap, 10);
	insert_Heap(heap, 5);
	insert_Heap(heap, 11);
	insert_Heap(heap, 2);
	insert_Heap(heap, 8);

	print_Heap(heap);
	
	printf("삭제된 값은 %d 입니다.\n", delete_Heap(heap));
	printf("삭제된 값은 %d 입니다.\n", delete_Heap(heap));
	
	print_Heap(heap);
	
	printf("삭제된 값은 %d 입니다.\n", delete_Heap(heap));
	printf("삭제된 값은 %d 입니다.\n", delete_Heap(heap));
	printf("삭제된 값은 %d 입니다.\n", delete_Heap(heap));
	
	print_Heap(heap);
		
	destroy_Heap(heap);
	
	return 0;
}

