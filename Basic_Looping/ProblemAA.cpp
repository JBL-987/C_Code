#include <stdio.h>
int main() {
    long long int N;
    scanf("%lld", &N);
    long long int k;
    int sum = 0;
    for (int i = 0; i < N; i++){
    	scanf("%lld", &k);
    	sum += k;
    	if (sum == 33){
		sum = 42;
		}
		else if (sum == 9){
			sum = 21;
		}
		else if (sum == 76){
			sum = 92;
		}
		else if (sum == 53){
			sum = 37;
		}
		else if (sum == 80){
			sum = 59;
		}
		else if (sum == 97){
			sum = 88;
		}
	}
	    printf("%lld\n", sum);		

    return 0;
}
