#include <stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	int N[T];
	for (int i = 0; i < T; i++){
		scanf("%d", &N[i]);
		long long int result = 0;
		long long int A[N[i]];
		for (int j = 0; j < N[i]; j++){
		scanf("%lld", &A[j]);
		result += A[j];
	    }
	    
	    printf("Case #%d: %lld\n", i + 1, result);
	}
	return 0;
}
