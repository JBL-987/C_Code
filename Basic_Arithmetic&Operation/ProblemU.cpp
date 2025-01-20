#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	long long int a, b;
	for (int i = 0; i < t; i++){
		scanf("%lld %lld", &a, &b);
		double clock = (a * (double)b) / 360.0;
		printf("%.2lf\n", clock);
	}
	return 0;
}
