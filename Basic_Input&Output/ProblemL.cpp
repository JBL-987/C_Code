#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);

    // Check if N is within the valid range
    if (N >= 1 && N <= 100) {
        printf("Selamat ulang tahun yang ke %d yaaa!\n", N);
    } else {
        printf("Error: N must be between 1 and 100.\n");
    }

    return 0;
}
