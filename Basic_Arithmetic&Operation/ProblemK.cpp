#include <stdio.h>
#include <math.h> 
int main(){
	int x;
	double y;
	scanf("%d %lf", &x, &y);
	double amount = x * pow((1 + y / 100), 3);
	printf("%.2lf\n", amount);
	return 0;
}

