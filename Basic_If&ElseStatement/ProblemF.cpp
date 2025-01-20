#include <stdio.h>

int main() {
    // Declare the budgets for Daging, Sayur, and Telur
    int d, s, t;
    
    // Read the input values
    scanf("%d %d %d", &d, &s, &t);

    // Declare arrays for names and budgets
    char *names[3] = {"Daging", "Sayur", "Telur"};
    int budgets[3] = {d, s, t};

    // Sort the budgets and corresponding names manually using simple sorting (Bubble Sort)
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (budgets[i] < budgets[j]) {
                // Swap the budgets
                int temp = budgets[i];
                budgets[i] = budgets[j];
                budgets[j] = temp;
                
                // Swap the names accordingly
                char *tempName = names[i];
                names[i] = names[j];
                names[j] = tempName;
            }
        }
    }

    // Output the sorted item names
    for (int i = 0; i < 3; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}

