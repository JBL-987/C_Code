#include <stdio.h>

#define SIZE 100

typedef struct{
   int id;
   int participant;
} Node;

Node arr[SIZE];
int nElement = 0;

void swap(Node *a, Node *b){
	Node temp = *a;
	*a = *b;
	*b = temp;
}

void upheap(int index) {
	if (index == 1){
		return;
	} else {
		int parent = index / 2;
		if (arr[index].id < arr[parent].id){
			swap(&arr[index], &arr[parent]);
		}
		upheap(parent);
	}
}

void downheap(int index){
	int toindex = index;
	int left = index * 2;
	int right = index * 2 + 1;
	
	if (left <= nElement && arr[left].id < arr[toindex].id){
		toindex = left;
	}
	
	if (right <= nElement && arr[right].id < arr[toindex].id){
		toindex = right;
	}
	
	if (index == toindex){
		return;
	}
	
	swap(&arr[index], &arr[toindex]);
	
	downheap(toindex);
}

void insertheap(int x){
	++nElement;
	arr[nElement].id = x;
	upheap(nElement);
}

void extractheap(){
	if (nElement == 0){
		return;
	} else if (nElement == 1){
		--nElement;
		return
	} else {
		swap(&arr[1], &arr[nElement]);
		--nElement;
		downheap(1);
	}
}

void printall(){
	for (int i = 1; i <= nElement; i++){
		printf("%d ", arr[i].id);
	}
	printf("\n");
}

void findmin() {
	printf("%d ", arr[1].id);
}

int main(){
	insertheap(10);	
	insertheap(30);	
	insertheap(20);	
	insertheap(5);
	printall();	
	return 0;
}

