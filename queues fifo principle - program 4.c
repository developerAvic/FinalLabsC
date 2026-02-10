#include <stdio.h>
#include <stdlib.h>

int *q; // Pointer to dynamically allocated array that stores queue elements.
int max, 
rear = -1, // Points to last inserted element. Starts at -1 because queue is empty initially. 
front = 0, 
count = 0; // Tracks number of elements present. This variable is extremely important because circular queues cannot rely only on front and rear to detect empty/full states safely.


// if queue is full say its full
//  else 
    // read the element to be inserted
    // When rear reaches last index and increments, modulo wraps it back to zero (i.e the first position of the queue).
    // insert element at the new rear position.
    // increment the element count.
    
void Enqueue(){
    int ele;

    if (count == max)
        printf("Queue overflow\n");
    else{
        printf("Enter the element to be inserted\n");
        scanf("%d", &ele);
        rear = (rear + 1) % max; // When rear reaches last index and increments, modulo wraps it back to zero (i.e the first position of the queue) .
        q[rear] = ele;
        count++;
    }
}


// if elements in queue is empty say its empty
// else 
    // display the about to be removed element i.e the first element in the queue
    // increase the front variable so tht the next element becomes the front
    // decrease the element count value

void Dequeue(){
    if (count == 0)
        printf("Queue underflow\n");
    else{
        printf("Deleted element is %d\n", q[front]);
        front = (front + 1) % max;
        count--;
    }
}


// if queue is empty say its empty
// else 
    // traverse the queue
        // point to the first element in queue to an variable k
        // run the for loop only for the number of elements present in queue rather than the max queue size. 
            // print the values of queue using k.
            // Moves index forward while wrapping around.

void display(){
    int i, k;

    if (count == 0)
        printf("Queue is empty\n");
    else{
        k = front; // point to the first element in queue
        for (i = 0; i < count; i++){ // run the for loop only for the number of elements present in queue rather than the max queue size. 
            printf("%d\n", q[k]);
            k = (k + 1) % max; // Moves index forward while wrapping around.
        }
    }
}


// get the max size of the queue
// allocate memory for the queue based on max 
// while loop with choice and switch statement for all 3 functions and exit.

int main(){
    int choice, ele;

    printf("Enter the size of the queue: ");
    scanf("%d", &max);

    q = (int *)malloc(max * sizeof(int));

    while (1){
        printf("\nEnter your choice\n");
        printf("1 for enqueue\n2 for dequeue\n3 for display\n4 for exit\n");
        scanf("%d", &choice);

        switch (choice){
            case 1: Enqueue(); break;
            case 2: Dequeue(); break;
            case 3: display(); break;
            case 4:
                free(q);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
