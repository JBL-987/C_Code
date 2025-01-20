#include <stdio.h>
#include <string.h>

int palindrome(char* S){
	int len = strlen(S);
	for (int k = 0; k < len/2; k++){
		if (S[k] !=  S[len - k - 1]){
			return 0;
		}
		return 1;
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		char S[1001];
		scanf("%s", S);
		if (palindrome(S)){
			printf("Case #%d: yes\n",i + 1);
		}
		else{
			printf("Case #%d: no\n",i + 1);
		}
	}
	return 0;
}
