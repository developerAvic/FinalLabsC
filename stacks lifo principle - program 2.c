
#include <stdio.h>
#include <stdlib.h>

int *a;
int max, top = -1;


// push function takes in the element to be pushed as parameter.
    // if the stack is full 
        // double the max value
        // resize the array according to max value
    // else preincrement the top of the array by one and push the element.
    
void push(int ele)
{
    if (top == max - 1)    // stack full
    {
        max = max * 2;     // double the size
        a = realloc(a, max * sizeof(int));
        printf("Stack full. Resized to %d and element is pushed.\n", max);
    }

    a[++top] = ele;
}


// if the top is empty return an error flag and a message
//else send the value of top element and later lose the top most element.

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -999;
    }

    return a[top--]; // use it, then lose it. i.e return a[top] and then decrement it.
}


// if top is empty return nothing along with a message
// else print the stack elements from top to bottom

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");
}


// get the maximum size of stack from user
// dynamically allocate the size of the array with the max value of stack
// run a while loop which runs until user selects exit
    // get the choices from user to either push pop display exit
        // push - get the element to be pushed from user and pass it as an argument to push()
        // pop - call pop() if not returned with error flag, display the popper element
        // display , free and default 

int main()
{
    int choice, ele;

    printf("Enter initial max size: ");
    scanf("%d", &max);

    a = (int *)malloc(max * sizeof(int));

    while (1)
    {
        printf("\nEnter choice:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &ele);
            push(ele);
            break;

        case 2:
            ele = pop();
            if (ele != -999)
                printf("Popped element = %d\n", ele);
            break;

        case 3:
            display();
            break;

        case 4:
            free(a);
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}
