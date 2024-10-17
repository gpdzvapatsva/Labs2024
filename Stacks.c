#include <stdio.h>
#include <stdlib.h>
#define SIZE 10  // Defining the size of the stack

int top = -1;    // Initially, the stack is empty, so top is -1
int my_stack[SIZE];  // Array to store the stack elements

// Function to push an element onto the stack
void push() {
    int number;
    if (top == SIZE - 1) {  // Check if the stack is full
        printf("Stack overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the number to be pushed onto the stack: ");
        scanf("%d", &number);
        top++;  // Increase the top index
        my_stack[top] = number;  // Add the number to the stack
        printf("Pushed %d onto the stack.\n", number);
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {  // Check if the stack is empty
        printf("Stack underflow! No elements to pop.\n");
    } else {
        printf("Popped %d from the stack.\n", my_stack[top]);
        top--;  // Decrease the top index
    }
}

//  display the elements in the stack
void display() {
    if (top == -1) {  // Check if the stack is empty
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("\nPosition is %d  %d \n ", i, my_stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {  // Infinite loop to keep the program running until exit
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
//we can use if statements for the menu
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();

                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("You have entered an invalid choice.\n");
        }
    }

    return 0;
}





