#include <stdio.h>

int main() {
    long long int T;
    scanf("%lld", &T);  
    for (int i = 0; i < T; i++) {
        long long int N;
        scanf("%lld", &N);  
        long long int V[N];  
        for (int j = 0; j < N; j++) {
            scanf("%lld", &V[j]); 
        }
        long long int max1 = V[0];   
        long long int max2 = -1;     
        for (int j = 1; j < N; j++) {
            if (V[j] > max1) {
                max2 = max1;
                max1 = V[j];
            } else if (V[j] > max2) {
                max2 = V[j];
            }
        }
        long long int Total = max1 + max2;  
        printf("Case #%d: %d\n", i + 1, Total);
    }
    
    return 0;
}

