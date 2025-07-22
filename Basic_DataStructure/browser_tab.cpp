#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int tab;
	struct node *next;
	struct node *prev;
}Node;

Node *head = NULL;
Node *tail = NULL;
Node *activetab = NULL;

Node *createnode(int tab){
	Node *newtab = (Node*)malloc(sizeof(Node));
	newtab->tab = tab;
	newtab->next = NULL;
	newtab->prev = NULL;
	return newtab;
}

void inserttail(int tab){
	Node *newtab = createnode(tab);
	if (tail == NULL){
		head = tail = activetab = newtab;
	} else {
		newtab->prev = tail;
		tail->next = newtab;
		tail = newtab;
	} 
	activetab = tail;
}

void deletehead(){
	if (head == NULL){
		return;
	} else if (head == tail){
		head = tail = activetab = NULL;
	} else {
		Node *temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
}

void deletetail(){
	if (tail == NULL){
		return;
	} else if (head == tail){
		head = tail = activetab = NULL;
	} else {
		Node *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
	}
}

void deletenode(int tab){
	if (head == NULL){
		return;
	} else if (tab == head->tab){
		if (head == activetab){
			if (head->next != NULL){
				activetab = head->next;
			}
		}
		deletehead();
	} else if(tab == tail->tab){
		if (tail == activetab){
			if (tail->prev != NULL){
				activetab = tail->prev;
			}
		}
		deletetail();
	} else {
		Node *temp = head;
		while (temp != NULL && temp->tab != tab){
			temp = temp->next;
		} if (temp == NULL){
			return;
		} else{
			if (temp == activetab){
				if (temp->next != NULL){
					activetab = temp->next;
				} else if (temp->prev != NULL){
					activetab = temp->prev;
				} 
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
		}
	}
}

void left(int step){
	for (int i = 0; i < step; i++){
		if(activetab == NULL || activetab->prev == NULL){
			return;
		}
		activetab = activetab->prev;
	}
}

void right(int step){
	for (int i = 0; i < step; i++){
		if(activetab == NULL || activetab->next == NULL){
			return;
		}
		activetab = activetab->next;
	}
}

void view(){
	if (head == NULL){
		printf("No tab\n");
		return;
	}
	Node *temp = head;
	while(temp != NULL ){
		if (temp == activetab){
			printf("[%d]", temp->tab);
		} else {
			printf("%d", temp->tab);
		}
		if (temp != NULL){
			printf(" ");
		}
		temp = temp->next;
	}
}

int main(){
	int n, choice;
	char command;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++){
		scanf(" %c", &command);	
		switch(command){
		   case 'o':
		        scanf("%d", &choice);	  
		        inserttail(choice);
		        break; 
		   case 'c':
		   	    scanf("%d", &choice);
			    deletenode(choice);
				break; 	  
		   case 'r':
		   	    scanf("%d", &choice);
			 	right(choice);
				break;    
		   case 'l':
		   	    scanf("%d", &choice);
			  	left(choice);
			  	break; 
		    default:
			    break; 	  
		}
	} 
	view();
	return 0;
}
