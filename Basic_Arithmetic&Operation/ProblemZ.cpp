#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
    	double a, b, c, d;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        double diamond_value = (a/1)*2+ (b/2)*4 + (c/3)*4 + (d/4)*2;
        printf("%.2f\n", diamond_value);
    }
    
    return 0;
}

