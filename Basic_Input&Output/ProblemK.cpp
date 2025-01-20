#include <stdio.h>

int main() {
    char N[100];
    char U[100];
    int A;

    scanf("%[^\n]", N);
    scanf("%s", U);
    scanf("%d", &A);

    printf("Name: %s\n", N);
    printf("NIS: %s\n", U);
    printf("Age: %d\n", A);
    return 0;
}

