#include <stdio.h>
#include <stdlib.h>

struct AVL {
    int key;
    struct AVL *left;
    struct AVL *right;
    int height;
};
typedef struct AVL node;

int getHeight(node *n) {
    if (n == NULL)
        return 0;  // A non-existent node has a height of 0
    return n->height;  // Return the stored height value
}

node* createNode(int key){
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;  // A new leaf node has a height of 1
    return n;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int getBalanceFactor(node *n){
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

node* leftRotate(node* y){
    node* x = y->left;  // Set 'x' as the left child of 'y'
    node* T2 = x->right; // T2' captures the right subtree of 'x'

    x->right = y; // Move 'y' down to become the right child of 'x'
    y->left = T2; // Attach the orphan 'T2' to the left of 'y'

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1; // Update y's height
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        // Update x's height
    return x;
}

node* rightRotate(node* x){
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

node* insert(node* n, int key){
    if (n == NULL)
        return createNode(key);

    if (key < n->key)
        n->left = insert(n->left, key);
    else if (key > n->key)
        n->right = insert(n->right, key);

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));

    int bf = getBalanceFactor(n);

    // Left Left Case
    if (bf > 1 && key < n->left->key)
        return leftRotate(n);
    // Right Right Case
    if (bf < -1 && key > n->right->key)
        return rightRotate(n);
    // Left Right Case
    if (bf > 1 && key > n->left->key) {
        n->left = rightRotate(n->left);
        return leftRotate(n);
    }
    // Right Left Case
    if (bf < -1 && key < n->right->key) {
        n->right = leftRotate(n->right);
        return rightRotate(n);
    }
    return n;
}

void printtree(node* root, int space, int n){
    int i;
    if (root == NULL)
        return;
    // space keeps track of the total indentation for the current level. As we go deeper into the tree, space gets larger.
    space += n;  // Increase the distance from the left margin

    printtree(root->right, space, n); // Visit the Right subtree

    printf("\n");
    for (i = n; i < space; i++)  // This prints the current node. The for loop pushes the number to the right based on its depth in the tree. The deeper the node, the further to the right it appears.
        printf(" ");  // 2. Print indentation
    printf("%d\n", root->key);  // 3. Print the actual value

    printtree(root->left, space, n);  // Visit the Left subtree
}

int main(){
    node* root = NULL;
    int n, i, key;

    printf("Enter the number of nodes\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the key\n");
        scanf("%d", &key);
        root = insert(root, key);
    }
    printtree(root, 0, 5);
    return 0;
}
