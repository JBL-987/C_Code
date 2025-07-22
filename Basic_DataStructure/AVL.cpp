#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    int height;
    struct node *left;
    struct node *right;
} Node;

Node *root = NULL;

Node *createnode(int val) {
    Node *current = (Node *)malloc(sizeof(Node));
    current->val = val;
    current->height = 0;
    current->left = NULL;
    current->right = NULL;
    return current;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *root) {
    if (root == NULL)
        return -1;
    return root->height;
}

int getbalance(Node *root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

Node *leftrotate(Node *x) {
    Node *y = x->right;
    Node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *rightrotate(Node *y) {
    Node *x = y->left;
    Node *t = x->right;

    x->right = y;
    y->left = t;

    // ? Perbaikan: hitung tinggi dari bawah ke atas
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *insert(Node *root, int val) {
    if (root == NULL)
        return createnode(val);
    else if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    else
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getbalance(root);

    // LL Case
    if (balance > 1 && val < root->left->val)
        return rightrotate(root);

    // RR Case
    if (balance < -1 && val > root->right->val)
        return leftrotate(root);

    // LR Case
    if (balance > 1 && val > root->left->val) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // RL Case
    if (balance < -1 && val < root->right->val) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

Node *minvalue(Node *root) {
    Node *current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node *removeNode(Node *root, int val) {
    if (root == NULL)
        return NULL;

    if (val < root->val)
        root->left = removeNode(root->left, val);
    else if (val > root->val)
        root->right = removeNode(root->right, val);
    else {
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
            root->val = temp->val;
            root->right = removeNode(root->right, temp->val);
        }
    }

    if (root == NULL)
        return NULL;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getbalance(root);

    // LL Case
    if (balance > 1 && getbalance(root->left) >= 0)
        return rightrotate(root);

    // LR Case
    if (balance > 1 && getbalance(root->left) < 0) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // RR Case
    if (balance < -1 && getbalance(root->right) <= 0)
        return leftrotate(root);

    // RL Case
    if (balance < -1 && getbalance(root->right) > 0) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

int search(Node* root, int val){
	if (root == NULL){
		return 0;
	} else if (root->val == val){
		return val;
	} else if (root->val > val){
		return search(root->left, val);
	} else {
		return search(root->right, val);
	}
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder traversal after insertion:\n");
    preorder(root);
    printf("\n");

    root = removeNode(root, 40);
    printf("Preorder traversal after deletion of 40:\n");
    preorder(root);
    printf("\n");

    return 0;
}

