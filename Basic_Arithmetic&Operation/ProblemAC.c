#include <stdio.h>
#include <math.h>
int main() {
	long long m;
	scanf("%lld", &m);
	m = pow(2, m) - 1;
	printf("%lld\n", m);
	return 0;
}