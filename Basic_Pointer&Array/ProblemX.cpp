#include <stdio.h>

int main() {
    long long int T;
    scanf("%lld", &T);
    for (int i = 0; i < T; i++) {
        long long int N, M;
        scanf("%lld %lld", &N, &M);
        long long int Total = 0;  
        for (int j = 0; j < N; j++) {
            long long int maxWeight = 0;
            for (int k = 0; k < M; k++) {
                long long int weight;
                scanf("%lld", &weight);
                if (k == 0 || weight > maxWeight) {
                    maxWeight = weight;
                }
            }
            Total += maxWeight;
        }
        printf("Case #%d: %lld\n", i + 1, Total);
    }
    return 0;
}

