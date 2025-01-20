#include <stdio.h>
int main(){
	double a;
	double b;
	scanf("%lf %lf", &a, &b);
	double c = a / b;
	double d = 100 / c;
	printf("%.4lf%%\n", d);
	return 0;
}
