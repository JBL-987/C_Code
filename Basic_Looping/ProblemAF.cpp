#include <stdio.h>

int count_set_bits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1; 
        num >>= 1; 
    }
    return count;
}

int main() {
    int T; 
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        int array[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }

        int valid_pairs = 0;
        int invalid_pairs = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int xor_value = array[i] ^ array[j];
                int set_bits_xor = count_set_bits(xor_value);
                if (set_bits_xor >= 3) {
                    valid_pairs++;
                } else {
                    invalid_pairs++;
                }
            }
        }
        printf("Case #%d: %d %d\n", t, valid_pairs, invalid_pairs);
    }

    return 0;
}

