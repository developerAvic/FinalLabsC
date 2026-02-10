#include<stdio.h>
#include<stdlib.h>

struct BST{
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST node;

node* insert(node *root, int key) { // node *root: This is the pointer to the current node being examined.
    if(root == NULL) { // checks for an empty spot, either tree has to be empty or weve reached the correct leaf node
        root = (node*)malloc(sizeof(node));
        root->data = key; // Assigns your input value to the data field of the new node.
        root->right = NULL;
        root->left = NULL;  // Since this is a new leaf node, its left and right children are initialized to NULL.
        return root;
    }

    if(key < root->data)  // if the root data is lesser than key
        root->left = insert(root->left, key); //insert the value to the left of the parent node. 
        // insert(root->left : this root->left will be having null value soo during recursion it hits root == null and it creates a new node and assigns the value to the data field.
    else if(key > root->data)
        root->right = insert(root->right, key);

    return root;
}

void inorder(node *root) {
    if(root != NULL) {
        inorder(root->left); // The function calls itself recursively on the left child. This keeps happening until it reaches the leftmost node in the tree (the smallest value).
        printf("%d ", root->data);
        inorder(root->right); // function calls itself recursively on the right child to visit all nodes that are larger than the current node.
    }
}

void preorder(node *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void search(node *root, int key) { // takes the whole root and the key to find
    if(root == NULL) { // we’ve searched down to the leaves and haven't found the key. The tree either doesn't contain the value, or the tree was empty to begin with.
        printf("Key not found\n");
        return;
    }

    if(root->data == key) {  
        printf("Key found\n");
        return;
    }

    if(key < root->data)  // If the key we want is smaller than the current node, the rules of a BST tell us that the value must be in the left subtree (if it exists at all).
        search(root->left, key); // The function calls itself recursively, moving one level deeper into the left child.
    else
        search(root->right, key);  // The function calls itself recursively, moving one level deeper into the right child.
}

int main() {
    int n, key, choice;
    node *root = NULL, *temp;

    printf("enter the number of nodes\n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("enter the element\n");
        scanf("%d", &key);
        root = insert(root, key);
    }

    while(1) {
        printf("enter 1 for inorder\n2 for preorder\n3 for postorder\n4 for search\n5 for exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("inorder is \n");
                inorder(root);
                break;

            case 2:
                printf("pre order is \n");
                preorder(root);
                break;

            case 3:
                printf("post order is \n");
                postorder(root);
                break;

            case 4:
                printf("enter the element to be searched");
                scanf("%d", &key);
                search(root, key);
                break;

            case 5:
                exit(0);

            default:
                printf("invalid choice\n");
        }
    }
}
