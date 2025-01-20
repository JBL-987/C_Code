#include <stdio.h>
#include <stdlib.h>  // for malloc and free

int main() {
    long long int N;  // Number of items
    scanf("%lld", &N);

    // Dynamically allocate memory for the prices array
    long long int* prices = (long long int*)malloc(N * sizeof(long long int));
    if (prices == NULL) {
        // Check for memory allocation failure
        printf("Memory allocation failed\n");
        return 1;
    }

    // Reading initial prices using pointers
    for (int i = 0; i < N; i++) {
        scanf("%lld", prices + i);  // prices + i is equivalent to &prices[i]
    }

    long long int Q;  // Number of updates
    scanf("%lld", &Q);

    // Processing each update
    for (int j = 0; j < Q; j++) {
        long long int A, B;
        scanf("%lld %lld", &A, &B);

        // Update the price of the A-th item to B using a pointer
        *(prices + (A - 1)) = B;  // Convert A (1-based) to array index (0-based)

        // Print the result after each update
        printf("Case #%d:", j + 1);
        
        for (int i = 0; i < N; i++) {
            // Use a space before each number except the first
            if (i == 0) {
                printf(" %lld", *(prices + i));  // First item without leading space
            } else {
                printf(" %lld", *(prices + i));  // Subsequent items with space
            }
        }
        printf("\n");  // New line after each case
    }

    // Free the dynamically allocated memory
    free(prices);

    return 0;
}

