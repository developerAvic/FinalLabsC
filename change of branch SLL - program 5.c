#include <stdio.h>
#include <stdlib.h>

//  structure to define a node of a singly linked list
struct SLL
{
    int usn;
    char name[20];
    char mode[20];
    struct SLL *next; // pointer to the next node.
};
typedef struct SLL node;
node *start = NULL; // start is the head of the linked list


// a function to create node 
    // Dynamically allocate memory for one node and return a pointer to it.
    // input the variables
    // point the next node to null
    // null

node* createNode() // node*: The function returns a pointer to a node structure, allowing the newly created node to be linked into a list elsewhere.
{
    node *newnode = (node*) malloc(sizeof(node));

    printf("Enter the USN: \n");
    scanf("%d", &newnode->usn);

    printf("Enter the Name: \n");
    scanf("%s", newnode->name);

    printf("Enter the mode (Regular/Lateral/COB/COC): \n");
    scanf("%s", newnode->mode);

    newnode->next = NULL; // New node always starts with next = NULL
    return newnode; 
}


// create a new node 
// if list is empty new node becomes first node.
// assign temp pointer to the first node
// and move the temp pointer to the last node
// if pointer is null attach the new node to the end of the existing node

void insertend() {
    node *newnode = createNode();
    node *temp; // temp used for traversal

    if (start == NULL) {
        start = newnode;
        return;
    }

    temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode; // By setting temp->next (which was NULL) to the address of newnode, you've extended the chain.

}


// start traversal from head
// if no lists say its empty
// while the pointer for the node is not null, print and point the pointer to the next node.

void display() {
    node *temp = start;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Students in the class are:\n");
    printf("USN\tNAME\tMode\n");

    while (temp != NULL) {
        printf("%d\t%s\t%s\n", temp->usn, temp->name, temp->mode);
        temp = temp->next;
    }
    printf("\n");
}


// assign temp pointer to the head of list, and decalre the previous node pointer, and key 
// if the list is empty print its empty
// get the value of key
// if first node matches (i.e head node)
    // store the address of the first node
    // move the pointer tot the next node
    // free the head node

void deletekey()
{
    node *temp = start, *prev;
    int key;

    if (start == NULL)
    {
        printf("List is empty. Deletion is not possible.\n");
        return;
    }

    printf("Enter the USN to be deleted:\n");
    scanf("%d", &key);

    // First node match
    if (start->usn == key){ // checks if the very first node is the one you want to delete.
        temp = start; // saves the address of the current first node. You need this because once you move the start pointer, you’d "lose" the address of the memory you need to free.
        start = start->next; // moves the head of the list to the second node.
        printf("Deleted USN: %d\n", temp->usn);
        free(temp); // It releases the memory back to the heap
        return;
    }

    // Search
    while (temp != NULL // this is not the end of list - true
    && temp->usn != key){ // this is not the key - true
        prev = temp; // Stays exactly one step behind. You need this because, in a singly linked list, nodes don't know who is behind them. If you find the target at temp, you need prev to "close the gap" by pointing to the node after temp
        
        temp = temp->next; // Moves ahead to check the next USN.
    }

    if (temp == NULL) { // if usn not found in the whole list
        printf("USN is not found, so can't delete.\n");
        return;
    }

    prev->next = temp->next;  // prev->next used to point to temp. Now, it points to whatever comes after temp. The temp node is now physically disconnected from the chain.
    
    printf("Deleted USN: %d\n", temp->usn);
    free(temp);
}

int main()
{
    int choice, n, i;

    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1 for insert\n");
        printf("2 for display\n");
        printf("3 for delete students based on USN\n");
        printf("4 for adding multiple students\n");
        printf("5 for exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertend();
                break;

            case 2:
                display();
                break;

            case 3:
                deletekey();
                break;

            case 4:
                printf("Enter the number of students:\n");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    insertend();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
