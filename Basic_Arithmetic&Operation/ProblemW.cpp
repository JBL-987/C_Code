#include <stdio.h>

int main() {
    int N1, N2, N3;
    scanf("%d %d %d", &N1, &N2, &N3);
    int mid1 = (N1 / 10) % 10;
    int mid2 = (N2 / 10) % 10;
    int mid3 = (N3 / 10) % 10;
    printf("%d\n", mid1);
    printf("%d\n", mid2);
    printf("%d\n", mid3);
    return 0;
}

