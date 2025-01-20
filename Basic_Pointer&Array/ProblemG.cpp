#include <stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
	    int N;
		scanf("%d", &N);
		long long int A[N];
		long long int B[N];
		long long int count = 0;
	    for (int j = 0; j < N; j++) {
	    		scanf("%lld", &A[j]);
        }
        for (int j = 0; j < N; j++) {
            scanf("%lld", &B[j]); 
        }
        for (int k = 0; k < N; k++) { 
                if (A[k] < B[k]) { 
                    count++; 
                }
        }
		printf("Case #%d: %lld\n", i + 1, count);
	}
	return 0;
}
