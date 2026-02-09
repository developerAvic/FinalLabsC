#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertTerm(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);
    struct Node* temp;

    if(head == NULL || e > head->exp) {
        newNode->next = head;
        return newNode;
    }

    temp = head;
    while(temp->next != NULL && temp->next->exp >= e) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void displayPolynomial(struct Node* head) {
    struct Node* temp = head;

    while(temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if(temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* poly = NULL;
    int n, c, e, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);
        poly = insertTerm(poly, c, e);
    }

    printf("Polynomial is:\n");
    displayPolynomial(poly);

    return 0;
}
