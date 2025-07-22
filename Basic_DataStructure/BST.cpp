#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct node {
    int val;
    char value[MAX];
    struct node *left;
    struct node *right;
} Node;

Node *root = NULL;

Node *createnode(int val, char value[]) {
    Node *c = (Node*)malloc(sizeof(Node));
    c->val = val;
    strcpy(c->value, value);
    c->left = NULL;
    c->right = NULL;
    return c;
}

Node *insert(Node *root, int val, char value[]) {
    if (root == NULL) {
        return createnode(val, value);
    } else if (val < root->val) {
        root->left = insert(root->left, val, value);
    } else if (val > root->val) {
        root->right = insert(root->right, val, value);
    } else {
        return root;
    }
    return root;
}

Node *deletion(Node *root, int val, char value[]) {
    if (root == NULL) {
        return root;
    }
    else if (val < root->val) {
        root->left = deletion(root->left, val, value);
    } else if (val > root->val) {
        root->right = deletion(root->right, val, value);
    } else {
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->val = temp->val;
        strcpy(root->value, temp->value);
        root->right = deletion(root->right, temp->val, temp->value);
    }
    return root;
}

int search(Node *root, int val) {
    if (root == NULL) {
        return 0;
    } else if (root->val == val) {
        return 1;
    } else if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d-%s, ", root->val, root->value);
        inorder(root->right);
    }
}

void replace(Node **root, int val, char value[]) {
    char newvalue[MAX];
    printf("Replace new value: ");
    scanf("%s", newvalue);
    getchar();
    if (*root == NULL) {
        printf("NULL\n");
        return;
    } else if (strcmp((*root)->value, newvalue) == 0) {
        printf("same value\n");
    } else {
        *root = deletion(*root, val, value);
        *root = insert(*root, val, newvalue);
    }
}

void replaceAll(Node *root, char targetValue[], char newValue[]) {
    if (root != NULL) {
        replaceAll(root->left, targetValue, newValue);  
        if (strcmp(root->value, targetValue) == 0) {   
            strcpy(root->value, newValue);               
        }
        replaceAll(root->right, targetValue, newValue); 
    }
}

int main() {
    root = insert(root, 10, "FALCON");
    root = insert(root, 25, "EAGLE");
    root = insert(root, 15, "HOATZIN");
    root = insert(root, 30, "BLACKBIRD");
    root = insert(root, 50, "HAWK");
    root = insert(root, 35, "BLACKHAWK");
    root = insert(root, 70, "BLACKBIRD");
    root = insert(root, 45, "BALDEAGLE");
    root = insert(root, 65, "FALCON02");
    inorder(root);
    printf("\n");
    replace(&root, 45, "BALDEAGLE"); //change blackbird word in specifics node
    inorder(root);
    printf("\n");
    replaceAll(root, "BLACKBIRD", "HAWK"); //change all the blackbird word
    printf("\n");
    inorder(root);
    return 0;
}
