#include <stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
	    int N;
		scanf("%d", &N);
		long long int A[N][N];
		int sum = 0;
	    for (int j = 0; j < N; j++) {
	    	for (int k = 0; k < N; k++){
	    		scanf("%lld", &A[j][k]); 
			}
        }
		printf("Case #%d:", i + 1);
		
		for (int j = 0;j < N; j++){
			long long int sum = 0;
			for (int k = 0;k < N; k++){
			sum += A[k][j]; 
			}
			printf(" %lld", sum);
		}
		printf("\n");
	}
	return 0;
}
