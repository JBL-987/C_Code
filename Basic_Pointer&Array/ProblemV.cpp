#include <stdio.h>
int main(){
	long long int T;
	scanf("%lld", &T);
	long long int N;
	int count = 0;
	for (int i = 0; i < T; i++){
		scanf("%lld", &N);
		long long int a = 0, b = 1;
        long long int count = 0;
		for(int j = 0; j < N; j++){
			if(j <= 1){
                count = j; 
            } else {
                count = a + b;
                a = b;
                b = count;
		}
	}
	printf("Case #%d: %lld\n",i + 1, count);
	}
	return 0;
}
