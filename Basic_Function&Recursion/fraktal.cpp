#include <stdio.h>

long long int count_asterisks(int x) {
    if (x <= 0) return 0;
    return count_asterisks(x - 1) + x + count_asterisks(x - 2);
}

int main(){
	long long int x;
	scanf("%lld", &x);
	getchar();
	printf("%lld\n", count_asterisks(x));
	return 0;
}
