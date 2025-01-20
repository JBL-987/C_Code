#include <stdio.h>

int main(){
    long long int L;
    long long int B;
    double H;
    scanf("%lld %lld %lf", &L, &B, &H);
    double total = B * H + 3 * (B * L);
    printf("%.3lf\n", total);
    return 0;
}

