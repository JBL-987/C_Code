#include <stdio.h>

int main() {
    int t, a, b, c;
    scanf("%d", &t);
    char results[t][4]; 
    
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a <= b + c) {
            sprintf(results[i], "yes");
        } else {
            sprintf(results[i], "no");
        }
    }
    for (int i = 0; i < t; i++) {
        printf("Case #%d: %s\n", i + 1, results[i]);
    }
    
    return 0;
}

