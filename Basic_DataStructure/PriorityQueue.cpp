#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct node {
	char nama[MAX];
	int umur;
	int status;
	struct node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *createnode(char nama[], int umur, int status){
	Node *curr = (Node*)malloc(sizeof(Node));
	
	strcpy(curr->nama, nama);
	curr->umur = umur;
	curr->status = status;
	curr->next = NULL;
	
	return curr;
}

void enqueue(char nama[], int umur, int status){
	Node *curr = createnode(nama, umur, status);
	
	if (head == NULL || status < head->status){
		curr->next = head;
		head = curr;
		if (tail == NULL){
			tail = curr;
			return;
		}
	}
	
	Node *temp = head;
	while(temp->next != NULL && temp->next->status <= status){
		temp = temp->next;
	}
	curr->next = temp->next;
	temp->next = curr;
	
	if (curr->next == NULL){
		tail = curr;
	}
}

void dequeue(){
	if (head != NULL){
		Node *temp = head;
	    head = head->next;
	    free(temp);
	}
}

void print(){
	Node * temp = head;
	printf("Linked List after entering data:\n");
	while (temp != NULL){
		printf("Nama: %s, Umur: %d, Status: %d\n", temp->nama, temp->umur, temp->status);
		temp = temp->next;
	}
}

void input(){
    int status, umur;
	char nama[MAX];
	scanf("%s %d %d", nama, &umur, &status);
	getchar();
	enqueue(nama, umur, status);
}

int main(){
	char option, option1;
	while (true){
		input();
		printf("stop the program? (y/n)\n");
	    scanf("%c", &option);
	    getchar();
	    if (option == 'y') {
	    	print();
	    	break;
		}
		else if (option != 'n') {
		    printf("wrong input\n");
		    break;
		} 
		
		printf("wants to dequeue? (y/n)\n");
		scanf("%c", &option1);
		getchar();
		if (option1 == 'y'){
			dequeue();
		}
		else if (option != 'n') {
			printf("wrong input\n");
			break;
		} 
	}
	return 0;
}
