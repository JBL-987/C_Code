#include <stdio.h>
int main(){
	double a;
	double b;
	scanf("%lf %lf", &a, &b);
	double c = (a - b) / a * 100;
	printf("%.2lf%%\n", c);
	return 0;
}
