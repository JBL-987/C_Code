#include <stdio.h>
int main(){
	long long int t;
	scanf("%lld", &t);
	long long int a, b;
	for (int i = 0;i < t; i++){
		scanf("%lld %lld", &a, &b);
		long long int total = a;
		long long int empty = a;
		while (empty >= b) {
            long long int new_tea = empty / b; 
            total += new_tea; 
            empty = empty % b + new_tea; 
        }
		printf("Case #%d: %lld\n", i + 1, total);
	}
	return 0;
}
