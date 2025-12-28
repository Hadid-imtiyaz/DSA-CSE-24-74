//perform a pre-order traversal in a binary tree without recursion
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Stack for nodes
struct Node* stack[MAX];
int top = -1;

// Push into stack
void push(struct Node* node) {
    stack[++top] = node;
}

// Pop from stack
struct Node* pop() {
    return stack[top--];
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Preorder traversal without recursion
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    push(root);

    while (!isEmpty()) {
        struct Node* curr = pop();
        printf("%d ", curr->data);

        if (curr->right != NULL)
            push(curr->right);

        if (curr->left != NULL)
            push(curr->left);
    }
}

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Main function
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Preorder Traversal: ");
    preorder(root);

    return 0;
}