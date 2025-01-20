#include <stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	int count[1001] = {0};
	for (int i = 0; i < T; i++){
		int A[i];
		scanf("%d", &A[i]);
		count[A[i]]++;
	}
	int max = 0;
	for (int j = 0; j < 1000; j++){
		 if (count[j] > max) {
            max = count[j];
        }
	}
	printf("%d\n", max);
	return 0;
}

