#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM 100

typedef struct node {
	int harga;
	char item[MAX_ITEM];
	struct node *next;
	struct node *prev;
} Node;

Node *head = NULL;

void inserthead(char item[],int harga){
    Node *current = (Node*)malloc(sizeof(Node));	
    if (current == NULL){
    	printf("Failed to allocate the memory\n");
    	return;
	}
    current->harga =harga;
	strcpy(current->item, item);
	current->next = NULL;
	current->prev = NULL;
	if (head == NULL){
		head = current;
	} else {
		head->prev = current;
		current->next = head;
	    head = current;	
	}
}

void deletehead(){
	if (head == NULL){
		printf("Tidak ada list belanjaan\n");
		return;
	} else {
		Node *temp = head;
	    head = head->next;
	    if (head != NULL){
	    	head->prev = NULL;
		}
		free(temp);
	}
}

Node* split(Node* head) {
    Node *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    if (temp) temp->prev = NULL;
    return temp;
}

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->harga < right->harga) {
        left->next = merge(left->next, right);
        if (left->next) left->next->prev = left;
        left->prev = NULL;
        return left;
    } else {
        right->next = merge(left, right->next);
        if (right->next) right->next->prev = right;
        right->prev = NULL;
        return right;
    }
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    Node* second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}

void sort(){
	if (head == NULL){
		printf("Tidak ada list untuk disorting\n");
		return;
	}
	head = mergeSort(head);
}

void count_total(){
	if (head == NULL){
		printf("Tidak ada list belanjaan\n");
	} else {
		int total = 0;
		Node *temp = head;
		while (temp != NULL){
			total += temp->harga;
			temp = temp->next;
		}
		printf("%d", total);
	}
}

void count_item(){
	if (head == NULL){
		printf("Tidak ada list belanjaan\n");
	} else {
		int total = 0;
		Node *temp = head;
		while (temp != NULL){
			char temp_item[MAX_ITEM];
		    strcpy(temp_item, temp->item);
		    char *jumlah_item = strtok(temp_item, " ,.!");
		    
			total++;
			jumlah_item = strtok(NULL, " ,.!");
			temp = temp->next;
		}
		printf("%d", total);
	}
}

void printall(){
	Node *temp = head;
	while (temp != NULL){
		printf("- %s %d\n", temp->item, temp->harga);
		temp = temp->next;
	}
	printf("\n");
}

void input(){
	while (true){
		int harga;
	    char item[MAX_ITEM];
		printf("Input item dan harganya kalau ingin keluar ketik (exit): ");
		scanf("%s", item);
		getchar();
		if (strcmp(item,"exit") == 0){
			break;
		}
		scanf("%d", &harga);
        getchar();
		inserthead(item, harga);
	}
}

int main(){
	input();
	sort();
	printall();
	printf("Total Belanjaan: \n");
	count_total();
	printf("Total item: \n");
	count_item();
	return 0;
}
