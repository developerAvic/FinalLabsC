#include <stdio.h>

int main() {
    int matrix[10][10];
    int sparse[100][3];  
    int rows, cols;
    int i, j, k = 1;  // k starts from 1 because row 0 stores metadata

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Store sparse matrix
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    // Metadata
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = k - 1;  // Number of non-zero elements

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Display sparse matrix
    printf("\nSparse Matrix Representation (Row Col Value):\n");
    for(i = 0; i < k; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
