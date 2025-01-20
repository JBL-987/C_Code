#include <stdio.h>
int main(){
	long long int x;
	long long int y;
	scanf("%lld %lld", &x, &y);
	long long int z = x / y;
	printf("%lld\n", z);
	return 0;
}
