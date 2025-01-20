#include <stdio.h>
int main(){
	long long int a;
	long long int b;
	long long int c;
	scanf("%lld %lld %lld", &a, &b, &c);
	long long int result = a * b * c;
	printf("%lld\n", result);
	return 0;
}
