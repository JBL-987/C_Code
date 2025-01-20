#include <stdio.h>

int main() {
    double N;
    double P;
    
    for (int i = 0; i < 4; i++) {
        scanf("%lf %lf", &N, &P);
        double result = P / (1 - N * 1.0 / 100);
        printf("$%.2lf\n", result);
    }    
    return 0;
}

