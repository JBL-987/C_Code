#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (A[i][j] == A[i][k]) {
                    printf("Nay\n");
                    return 0;
                }
            }
        }
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            for (int k = i + 1; k < N; k++) {
                if (A[i][j] == A[k][j]) {
                    printf("Nay\n");
                    return 0;
                }
            }
        }
    }

    printf("Yay\n");
    return 0;
}

