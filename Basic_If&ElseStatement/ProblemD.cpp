#include <stdio.h>

int main() {
    int T; // Number of test cases
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, M;
        scanf("%d %d", &N, &M);

        // Calculate the number of acquaintances
        long long acquaintances = (long long)N * M;

        // Check if the number of acquaintances is odd or even
        if (acquaintances % 2 == 0) {
            printf("Case #%d: Party time!\n", t);
        } else {
            printf("Case #%d: Need more frogs\n", t);
        }
    }

    return 0;
}

