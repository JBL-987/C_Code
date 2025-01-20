#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int urutan;
    char *nama;
} Tanaman;

void swap(Tanaman *a, Tanaman *b) {
    Tanaman temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Tanaman *tanaman, int low, int high) {
    char *pivot = tanaman[high].nama;
    int left = low;
    int right = high - 1;
    
    while (left <= right) {
        while (left <= right && strcmp(tanaman[left].nama, pivot) < 0) {
            left++;
        }
        while (left <= right && strcmp(tanaman[right].nama, pivot) >= 0) {
            right--;
        }
        if (left <= right) {
            swap(&tanaman[left], &tanaman[right]);
        }
    }
    swap(&tanaman[left], &tanaman[high]);
    return left;
}

void quicksort(Tanaman *tanaman, int low, int high) {
    if (low < high) {
        int p = partition(tanaman, low, high);
        quicksort(tanaman, low, p - 1);
        quicksort(tanaman, p + 1, high);
    }
}

int main() {
    FILE *fp;
    int n;
    Tanaman *tanaman;
    fp = fopen("testdata.in", "r");
    if (fp == NULL) {
        printf("File is empty\n");
        return 1;
    }
    
    if (fscanf(fp, "%d", &n) != 1) {
        printf("Error reading n\n");
        fclose(fp);
        return 1;
    }

    tanaman = (Tanaman*)malloc(n * sizeof(Tanaman));
    if (tanaman == NULL) {
        printf("Tanaman Null\n");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        tanaman[i].nama = (char*)malloc(100 * sizeof(char));  
        if (tanaman[i].nama == NULL) {
            printf("Memory allocation failed for nama\n");
            for (int j = 0; j < i; j++) {
                free(tanaman[j].nama);
            }
            free(tanaman);
            fclose(fp);
            return 1;
        }
        if (fscanf(fp, "%d#%[^\n]", &tanaman[i].urutan, tanaman[i].nama) != 2) {
            printf("Error reading data at line %d\n", i + 1);
            for (int j = 0; j <= i; j++) {
                free(tanaman[j].nama);
            }
            free(tanaman);
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    quicksort(tanaman, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d %s\n", tanaman[i].urutan, tanaman[i].nama);
        free(tanaman[i].nama);
    }
    free(tanaman);
    return 0;
}
