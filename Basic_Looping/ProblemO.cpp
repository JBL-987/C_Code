#include <stdio.h>

int main() {
    int T;  // Jumlah test case
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        
        int max_portion = K;  // Mulai dengan porsi mula-mula
        
        for (int i = 0; i < N; i++) {
            int Xi;
            scanf("%d", &Xi);
            
            // Cari porsi terbesar yang lebih besar dari K tapi tidak melebihi M
            if (Xi > K && Xi <= M) {
                if (Xi > max_portion) {
                    max_portion = Xi;
                }
            }
        }
        
        // Cetak hasil dalam format yang diminta
        printf("Case #%d: %d\n", t, max_portion);
    }
    
    return 0;
}

