#include <stdio.h>

int main(){
	long long int a;
	long long int b;
	long long int c;
	long long int d;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	if (a * b == c - d){
		printf("True\n");
	}
	else {
		printf("False\n");
	}
	return 0;
}
