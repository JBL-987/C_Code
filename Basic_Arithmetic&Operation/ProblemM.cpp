#include <stdio.h>
int main(){
	double a;
	double b;
	scanf("%lf %lf", &a, &b);
	double c = b / a;
	double d = 100 / c;
	printf("%.2lf%%\n", d);
	return 0;
}
