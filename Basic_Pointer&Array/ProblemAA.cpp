#include <stdio.h>
int main(){
	long long int N;
	scanf("%lld", &N);
	long long int A[N];
	for (int i = 0; i < N; i++){
		scanf("%lld", &A[i]);
	}
	long long unique = 0;
	int isUnique;
	for (int i = 0; i < N; i++){
		isUnique = 1;
		 for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {  // Found a duplicate
                isUnique = 0;
                break;
            }
        }
        // If unique, increment count
        if (isUnique) {
            unique++;
        }
    }
    // Output the number of unique room requests
    printf("%lld\n", unique);
	return 0;
}
