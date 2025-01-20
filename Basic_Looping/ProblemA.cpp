#include <stdio.h>
int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    while (N > 0) {
        printf("%d\n", M++);
        N--;
    };
    return 0;
}
