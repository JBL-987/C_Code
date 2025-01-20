#include <stdio.h>
#include <string.h>

// Helper function to swap two integers
void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to swap two characters
void swap_char(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char letters[3];   // Array to store the letters
    int positions[3];  // Array to store the original positions

    // Read the input letters (assumed to be space-separated)
    scanf(" %c %c %c", &letters[0], &letters[1], &letters[2]);

    // Initialize positions to their original order (1-based index)
    for (int i = 0; i < 3; i++) {
        positions[i] = i + 1;
    }

    // Sort the letters and track the original positions
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (letters[i] > letters[j]) {
                // Swap letters
                swap_char(&letters[i], &letters[j]);
                // Swap corresponding positions
                swap_int(&positions[i], &positions[j]);
            }
        }
    }

    // Print the original positions after sorting the letters
    printf("%d %d %d\n", positions[0], positions[1], positions[2]);

    return 0;
}

