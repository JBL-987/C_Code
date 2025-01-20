#include <stdio.h>

#define MAX_SIZE 50  // Maximum size for the matrices

int main() {
    int T;
    scanf("%d", &T);  // Read the number of test cases
    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);  // Read the size of the matrices (up to 50)

        long long int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
        
        // Read first matrix A
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%lld", &A[j][k]); 
            }
        }
        
        // Read second matrix B
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%lld", &B[j][k]); 
            }
        }
        
        // Read third matrix C
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%lld", &C[j][k]); 
            }
        }

        // Prepare to store the results of intermediate multiplication AB
        long long int AB[MAX_SIZE][MAX_SIZE] = {0}; // Declare AB matrix

        // Multiply A and B to get AB
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                AB[j][k] = 0; // Initialize to zero
                for (int l = 0; l < N; l++) {
                    AB[j][k] += A[j][l] * B[l][k]; // Matrix multiplication A * B
                }
            }
        }

        // Prepare to store the final result ABC
        long long int ABC[MAX_SIZE][MAX_SIZE] = {0}; // Declare ABC matrix

        // Multiply AB and C to get ABC
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ABC[j][k] = 0; // Initialize to zero
                for (int l = 0; l < N; l++) {
                    ABC[j][k] += AB[j][l] * C[l][k]; // Matrix multiplication AB * C
                }
            }
        }

        // Output the result
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (k > 0) {
                    printf(" "); // Print space before the element if it's not the first element
                }
                printf("%lld", ABC[j][k]); // Print each element
            }
            printf("\n"); // New line after each row
        }
    }
    return 0;
}

