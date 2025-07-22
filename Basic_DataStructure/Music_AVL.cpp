#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

typedef struct node {
	struct node *left;
	struct node *right;
	int height;
	char title[SIZE];
	char singer[SIZE];
	char type[SIZE];
} Node;

Node *root = NULL;

Node *createnode(char *title, char *singer, char *type){
	Node *current = (Node*)malloc(sizeof(Node));
	strcpy(current->title, title); 
    strcpy(current->singer, singer);
    strcpy(current->type, type);
	current->left = NULL;
	current->right = NULL;
	current->height = 0;
	return current;
}

int max(int a, int b){
	if (a > b){
		return a;
	} else {
		return b;
	}
}

int height(Node *root){
	if (root == NULL){
		return -1;
	} else {
		return root->height;
	}
}

int getbalance(Node *root){
	if (root == NULL){
		return 0;
	} else {
		return height(root->left) - height(root->right);
	}
}

Node *leftrotate(Node *root){
	Node *newnode = root->right;
	Node *temp = newnode->left;
	
	newnode->left = root;
	root->right = temp;
	
	root->height = max(height(root->left), height(root->right)) + 1;
    newnode->height = max(height(newnode->left), height(newnode->right)) + 1;
	
	return newnode;
}

Node *rightrotate(Node *root){
	Node *newnode = root->left;
	Node *temp = newnode->right;
	
	newnode->right = root;
	root->left = temp;
	
	root->height = max(height(root->left), height(root->right)) + 1;
    newnode->height = max(height(newnode->left), height(newnode->right)) + 1;
	
	return newnode;
}

Node *insert(Node *root, char *title, char *singer, char *type){
	if (root == NULL){
		return createnode(title, singer, type);
	} else if (strcmp(title, root->title) < 0){
		root->left = insert(root->left, title, singer, type);
	} else if (strcmp(title, root->title) > 0){
		root->right = insert(root->right, title, singer, type);
	} else {
		return root;
    }
		
		root->height = max(height(root->left), height(root->right)) + 1;
		int balance = getbalance(root);
		
		if (balance > 1 && strcmp(title, root->left->title) < 0){
			return rightrotate(root);
		} else if (balance > 1 && strcmp(title, root->left->title) > 0){
			root->left = leftrotate(root->left);
			return rightrotate(root);
		} else if (balance < -1 && strcmp(title, root->right->title) > 0){
			return leftrotate(root);
		} else if (balance < -1 && strcmp(title, root->right->title) < 0){
			root->right = leftrotate(root->right);
			return leftrotate(root);
		}
		else {
			return root;
	    }
}

Node *minvalue(Node *root) {
    Node *current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node *deletion(Node *root, char *title){
	if (root == NULL){
		return NULL;
	} else if (strcmp(title, root->title) < 0){
		root->left = deletion(root->left, title);
	} else if (strcmp(title, root->title) > 0){
		root->right = deletion(root->right, title);
	} else {
		
		if ((root->left == NULL) || (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node *temp = minvalue(root->right);
            strcpy(root->title, temp->title); 
            strcpy(root->singer, temp->singer);
            strcpy(root->type, temp->type);
            root->right = deletion(root->right, temp->title);
        }
	}
	
	root->height = max(height(root->left), height(root->right)) + 1;
	int balance = getbalance(root);
		
	if (balance > 1 && strcmp(title, root->left->title) < 0){
		rightrotate(root);
	} else if (balance > 1 && strcmp(title, root->left->title) > 0){
		root->left = leftrotate(root->left);
		return rightrotate(root);
	} else if (balance < -1 && strcmp(title, root->right->title) > 0){
		leftrotate(root);
	} else if (balance < -1 && strcmp(title, root->right->title) < 0){
		root->right = leftrotate(root->right);
		return leftrotate(root);
	}
	else {
		return root;
	}
}

void preorder(Node *root, int *i){
	if (root == NULL){
		return;
	} else {
		(*i)++;
		printf("%d | %s | %s | %s\n", *i, root->title, root->singer, root->type);
		preorder(root->left, i);
		preorder(root->right, i);
	}
}

void menu(){
	int i = 0;
	printf("Music List (printed in preoder)\n");
	printf("=========================================================\n");
	printf("No. | Title                    | Singer        | Type    \n");
	printf("=========================================================\n");
	preorder(root, &i);
	printf("Menu\n");
	printf("1. Add Data\n");
	printf("2. Delete Data\n");
	printf("3. Exit\n");
}

int main(){
	int option;
	char title[30];
	char singer[30];
	char type[30];
	menu();
	while (true) {
		printf(">>");
	    scanf("%d", &option);
	    getchar();
	    switch (option){
	    	case 1:
	    		system("cls");
	    		printf("Enter title to insert: ");
	    		scanf("%[^\n]", title);
	    		getchar(); 
	    		printf("Enter singer to insert: ");
	    		scanf("%[^\n]", singer);
	    		getchar(); 
	    		while (true){
				   printf("Enter type to insert: ");
	    		   scanf("%s", type);
	    		   getchar(); 
	    		   if (strcmp(type,"Rock") != 0 && strcmp(type,"Jazz") != 0 && strcmp(type,"Pop") != 0 && strcmp(type,"rock") != 0 && strcmp(type,"jazz") != 0 && strcmp(type,"pop") != 0){
	    			    printf("invalid type of music\n");
	    			    continue;
				    } else {
				        root = insert(root, title, singer, type);
	    		        break;	
			 	    }
				}
				break;
	        case 2:
	        	system("cls");
	        	printf("Enter title to delete: ");
	        	scanf("%[^\n]", title);
	        	getchar(); 
	    		root = deletion(root, title);
	    		break;
	    	case 3:
	    		exit(0);
	    		break;
	    	default:
	    		printf("Wrong Output\n");
	    		system("cls");
	    		continue;
		}
		menu();
	}
	return 0;
}
