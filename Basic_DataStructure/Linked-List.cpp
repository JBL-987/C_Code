#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct node {
	char pokemon[MAX];
	struct node *next;
} Node;

Node *head = NULL;

void inserthead(char pokemon[]){
    Node *current = (Node*)malloc(sizeof(Node));	
    if (current == NULL){
    	printf("allocate current failed\n");
    	return;
	}
	strcpy(current->pokemon, pokemon);
	current->next = NULL;
	if (head == NULL){
		head = current;
	} else {
		current->next = head;
		head = current;
	}
}

void deletehead(){
	if (head == NULL){
		printf("there is no pokemon to delete\n");
		return;
	} else {
		Node *temp = head;
	    head = head->next;
		free(temp);
	}
}

void printall(char pokemon[]){
	if (head == NULL){
		printf("there is no link to be printed\n");
		return;
	}
	Node *temp = head;
	while (temp != NULL){
		printf("- %s\n", temp->pokemon);
		temp = temp->next;
	}
}

void input_pokemon_name() {
    char name_pokemon[MAX];
    char choice;
    choice = tolower(choice);
    while (true) {
        printf("Enter the name of the Pokemon: ");
        scanf("%s", name_pokemon);
        getchar(); 
        inserthead(name_pokemon);
        while (true) {
            printf("Do you want to delete the Pokemon? (y/n): ");
            scanf(" %c", &choice);
            getchar();
            if (choice == 'y' || choice == 'n') break;
            printf("Please enter a valid input (y/n)\n");
        }
        if (choice == 'y') {
            deletehead();
        }
        while (true) {
            printf("Do you want to add another Pokemon? (y/n): ");
            scanf(" %c", &choice);
            getchar();
            if (choice == 'y' || choice == 'n') break;
            printf("Please enter a valid input (y/n)\n");
        }
        if (choice == 'n') break;
    }
    printall(name_pokemon);
}

int main(){
    input_pokemon_name();
    return 0;
}
