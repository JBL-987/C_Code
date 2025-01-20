#include <stdio.h>
int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    while (N > 0) {
        printf("%d\n", M++);
        N--;
    };
    printf("%d\n", M);
    return 0;
}
