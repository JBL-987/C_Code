#include <stdio.h>

int main() {
    char input[100]; // Menyimpan setiap baris input
    long long int results[3];  // Menyimpan hasil dari tiga ekspresi
    long long int A, B, C, D;

    // Membaca 3 baris input
    for (int i = 0; i < 3; i++) {
        fgets(input, sizeof(input), stdin);

        // Mengambil nilai A dan B dari input
        sscanf(input, "(%lld+%lld)x(%lld-%lld)", &A, &B, &C, &D);

        // Menghitung hasil (A+B) * (C-D)
        results[i] = (A + B) * (C - D);
    }

    // Menampilkan hasil dalam satu baris
    printf("%lld %lld %lld\n", results[0], results[1], results[2]);

    return 0;
}

