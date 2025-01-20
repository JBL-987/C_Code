#include <stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		double a;
		double b;
		scanf("%lf %lf", &a, &b);
		double result = a/100 * b;
		printf("%.2lf\n", result);
	}
	return 0;
}
