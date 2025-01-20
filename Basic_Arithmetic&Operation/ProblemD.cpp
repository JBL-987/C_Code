#include <stdio.h>
int main(){
	int N;
	int M;
	scanf("%d %d", &N, &M);
	int K = M + 1;
	for(int i = 0;i < K; i++){
		printf("%d\n", N++);
	}
	return 0;
}

