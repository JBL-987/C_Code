#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30  

typedef struct node {
    char name[SIZE];
    char condition[SIZE];
    struct node *next;
    struct node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

Node *createnode(char *name, char *condition) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->name, name);
    strcpy(newnode->condition, condition);
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void inserthead(char *name, char *condition) {
    Node *newnode = createnode(name, condition);
    if (head == NULL) {
        head = tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void inserttail(char *name, char *condition) {
    Node *newnode = createnode(name, condition);
    if (tail == NULL) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertmid(char *name, char *condition){
	if (head == NULL){
		inserthead(name, condition);
	} else if (head->next == NULL){
		inserttail(name, condition);
	} else {
		Node *newnode = createnode(name, condition);
		Node *slow = head;
		Node *fast = head;
		while (fast->next != NULL && fast->next->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		newnode->next = slow->next;
		newnode->prev = slow;
		
		if(slow->next != NULL){
			slow->next->prev = newnode;
		} else {
			tail = newnode;
		}
		slow->next = newnode;
	}
}

void queue(char *name, char *condition) {
    if (strcmp(condition, "Critical") == 0) {
        inserthead(name, condition);  
    } else if (strcmp(condition, "Serious") == 0) {
       insertmid(name, condition);
    } else if (strcmp(condition, "Fair") == 0 || strcmp(condition, "Good") == 0) {
    	inserttail(name, condition);
    } 
}

void deletehead() {
    if (head == NULL) {
        printf("There is no patient waiting\n");
        return;
    } else {
        char patientName[SIZE];
        char patientCondition[SIZE];
        strcpy(patientName, head->name);
        strcpy(patientCondition, head->condition);
        
        if (head == tail) {
            free(head);
            head = tail = NULL;
        } else {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            free(temp);
        }
        
        if (strcmp(patientCondition, "Critical") == 0) {
            printf("%s is in the Emergency Room\n", patientName);
        } else if (strcmp(patientCondition, "Serious") == 0) {
            printf("%s is in the Examination Room\n", patientName);
        } else {
            printf("%s is in the Consultation Room\n", patientName);
        }
    }
}

void view() {
    if (head == NULL) {
        printf("None\n");
        return;
    }
    Node *temp = head;
    printf("Waiting Room: ");
    while (temp != NULL) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
}

int main() {
    int n;
    char command[SIZE], name[SIZE], condition[SIZE];
    scanf("%d", &n);
    getchar();  
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        getchar();  
        if (strcmp(command, "ADD") == 0) {
            scanf("%s %s", name, condition);
            getchar(); 
            queue(name, condition);
        } else if (strcmp(command, "CALL") == 0) {
            deletehead();
        } else {
            printf("wrong command\n");
        }
    }
    view();
    return 0;
}

