#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

typedef struct {
    char nama[MAX_SIZE];
    int urutan;
} Matkul;

void merge(Matkul *matakuliah, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    Matkul left[n1], right[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = matakuliah[low + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = matakuliah[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i].urutan < right[j].urutan || 
           (left[i].urutan == right[j].urutan && strcmp(left[i].nama, right[j].nama) < 0)) {
            matakuliah[k] = left[i];
            i++;
        } else {
            matakuliah[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        matakuliah[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        matakuliah[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(Matkul *matakuliah, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(matakuliah, low, mid);
        mergeSort(matakuliah, mid + 1, high);
        merge(matakuliah, low, mid, high);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    Matkul matakuliah[MAX_SIZE];
    for (int i = 0; i < t; i++) {
        scanf("%s %d", matakuliah[i].nama, &matakuliah[i].urutan);
    }

    mergeSort(matakuliah, 0, t - 1);

    for (int i = 0; i < t; i++) {
        printf("%s\n", matakuliah[i].nama);
    }
    return 0;
}

