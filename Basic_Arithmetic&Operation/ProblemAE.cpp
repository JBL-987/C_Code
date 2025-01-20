#include <stdio.h>
int main(){
	long long int N;
	scanf("%lld", &N);
	long long int total = 0;
	for (int i = 0; i < N; i++){
		long long int damage = 100 + (i * 50);
		total += damage;
	}
	printf("%lld\n", total);
	return 0;
}
