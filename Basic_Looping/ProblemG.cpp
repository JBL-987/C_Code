#include <stdio.h>

int main() {
    int t;
    int sum = 0; // Initialize sum before the loop

    scanf("%d", &t);  // Read the number of inputs

    int n[t];  // Declare an array of size t to hold the inputs

    for (int i = 0; i < t; i++) {
        scanf("%d", &n[i]);  // Read each number into the array
        sum += n[i];  // Add the number to the running sum
    }

    printf("%d\n", sum);  // Print the total sum after the loop
    return 0;
}

