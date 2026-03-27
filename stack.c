#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
struct Stack {
    int top;
    int items[MAX];
};

// Initialize the stack
void initStack(struct Stack* s) {
    s->top = -1; // Empty stack
}

// Check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->top++;
    s->items[s->top] = value;
    printf("%d pushed onto stack\n", value);
}

// Pop an element from the stack
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1; // Return -1 to indicate failure
    }
    int value = s->items[s->top];
    s->top--;
    return value;
}

// Display all elements in the stack
void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Popped element: %d\n", pop(&s));
    display(&s);

    return 0;
}
