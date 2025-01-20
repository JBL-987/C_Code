#include <stdio.h>
#include <string.h>

int main(){
	long long int T;
	scanf("%lld", &T);
	for (int i = 0; i < T; i++){
		char S[1001];
		scanf("%s", S);
		printf("Case %d: ", i + 1);
		for (int j = 0; j < strlen(S); j++) {
            printf("%d", S[j]);  
            if (j < strlen(S) - 1) {
                printf("-");  
            }
		}
        printf("\n");
	}
	return 0;
}
