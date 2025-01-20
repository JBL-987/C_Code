#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);  // Read the size of the array

    int Q[N];  // Declare the array of size N
    for (int i = 0; i < N; i++) {
        scanf("%d", &Q[i]);  // Read elements into the array
    }

    int S;
    scanf("%d", &S);  // Read the number of queries

    for (int j = 0; j < S; j++) {
        int A, B;
        scanf("%d %d", &A, &B);  // Read the query indices
        
        int sum = 0;
        // Note: Adjust A to be zero-based and ensure B is not out of bounds
        for (int k = A - 1; k < B; k++) {  
            sum += Q[k];  // Calculate the sum from index A-1 to B-1
        }

        printf("Case #%d: %d\n", j + 1, sum);  // Print the result for this query
    }

    return 0;
}

