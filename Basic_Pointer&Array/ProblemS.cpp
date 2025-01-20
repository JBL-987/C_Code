#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        int result = 0, place = 1;
        while (A > 0 || B > 0) {
            int digitA = A % 10; 
            int digitB = B % 10; 
            int sum = (digitA + digitB) % 10; 
            result += sum * place; 
            place *= 10; 
            A /= 10; 
            B /= 10; 
        }
        printf("Case #%d: %d\n", i, result);
    }
    
    return 0;
}

