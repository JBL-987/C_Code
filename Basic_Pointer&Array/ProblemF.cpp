#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    long long int T;
    scanf("%lld", &T);  
    char S[100001];  
    for (int i = 0; i < T; i++) {
        scanf("%s", S); 
        bool seen[26] = {false};  
        int distinctCount = 0; 

        for (int j = 0; S[j] != '\0'; j++) {
            int index = S[j] - 'a';  
            if (!seen[index]) {  
                seen[index] = true;  
                distinctCount++;  
            }
        }

        if (distinctCount % 2 == 0) {
            printf("Case #%d: Yay\n", i + 1);  
        } else {
            printf("Case #%d: Ewwww\n", i + 1);  
        }
    }
    return 0;
}

