#include <stdio.h>

// Binary search untuk mencari posisi pertama dari X
int binary_search(int N, int X, int *A) {
    int left = 0;  // Karena array 1-based, kita mulai dari 0
    int right = N - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (A[mid] == X) {
            result = mid;  // Catat posisi yang ditemukan
            right = mid - 1;  // Lanjut cari ke kiri untuk menemukan yang pertama
        }
        else if (A[mid] < X) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    if (result == -1) return -1;
    return result + 1;  // Konversi ke 1-based indexing
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    for (int i = 0; i < Q; i++) {
        int X;
        scanf("%d", &X);
        printf("%d\n", binary_search(N, X, A));
    }
    
    return 0;
}
