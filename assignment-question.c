//implement a queue using two stacks
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push operation
void push(struct Stack *s, int x) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = x;
}

// Pop operation
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->arr[s->top--];
}

// Queue using two stacks
struct Stack s1, s2;

// Enqueue operation
void enqueue(int x) {
    push(&s1, x);
    printf("Enqueued: %d\n", x);
}

// Dequeue operation
void dequeue() {
    int x;

    if (isEmpty(&s1) && isEmpty(&s2)) {
        printf("Queue is Empty\n");
        return;
    }

    if (isEmpty(&s2)) {
        while (!isEmpty(&s1)) {
            x = pop(&s1);
            push(&s2, x);
        }
    }

    x = pop(&s2);
    printf("Dequeued: %d\n", x);
}

// Display queue
void display() {
    if (isEmpty(&s1) && isEmpty(&s2)) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = s2.top; i >= 0; i--)
        printf("%d ", s2.arr[i]);

    for (int i = 0; i <= s1.top; i++)
        printf("%d ", s1.arr[i]);

    printf("\n");
}

// Main function
int main() {
    initStack(&s1);
    initStack(&s2);

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    dequeue();
    dequeue();
    display();

    return 0;
}