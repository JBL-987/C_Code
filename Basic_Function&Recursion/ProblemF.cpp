#include <stdio.h>
#include <string.h>
#define MAX 1000

void reverse(char *S) { 
   int len = strlen(S);
   for (int i = 0; i < len / 2; i++){
       char temp = S[i];
	   S[i] = S[len - i - 1];
	   S[len - i - 1] = temp;
   }
}

int main() {
    int T;
    scanf("%d", &T);
    getchar();  
    char S[MAX];
    for (int i = 0; i < T; i++) {
        scanf("%[^\n]", S);
        getchar();  
        reverse(S);
        printf("Case #%d: %s\n", i + 1, S);
    }
    return 0;
}
