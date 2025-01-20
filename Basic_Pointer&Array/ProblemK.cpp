#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main(){
	int N;
	scanf("%d", &N);
	char S[1001];
	for (int i = 0; i < N; i++){
		scanf("%s", S);
		
		reverseString(S);
		
		printf("Case #%d : %s\n", i + 1, S);
	}
	return 0;
}
