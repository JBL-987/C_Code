#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    long long int c;
    for (int i = 0; i < t; i++){
        scanf("%lld", &c);

        double r = (4.0 * c) / 5.0;      
        double f = (9.0 * c) / 5.0 + 32; 
        double k = c + 273.00;           

        printf("%.2lf %.2lf %.2lf\n", r, f, k);
    }
    return 0;
}

