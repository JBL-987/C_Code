#include <stdio.h>

typedef struct{
	char nama[31];
	int ukuran;
}Pesanan;

void swap(Pesanan *a, Pesanan *b){
	Pesanan temp = *a;
	*a = *b;
	*b = temp;
}

int partition(Pesanan *pesan, int low, int high){
	int pivot = pesan[high].ukuran;
	int left = low;
	int right = high- 1;
	while (left <= right){
		while (left <= right && pesan[left].ukuran < pivot){
			left++;
		}
		while (left <= right && pesan[right].ukuran >= pivot){
			right--;
		}
		if (left <= right){
			swap(&pesan[left], &pesan[right]);
		}
	}
	swap(&pesan[left], &pesan[high]);
	return left;
}

void quicksort(Pesanan *pesan, int low, int high){
	if (low < high){
		int p = partition(pesan, low, high);
		quicksort(pesan, low, p - 1);
		quicksort(pesan, p + 1, high);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	Pesanan pesan[n];
	int harga = 0;
	for (int i = 0; i < n; i++){
		scanf("%[^#]#%d", pesan[i].nama, &pesan[i].ukuran);
	}
	
	quicksort(pesan, 0, n - 1);
	
	for (int i = 0; i < n; i++){
	 int harga = 0;
        if (pesan[i].ukuran > 0 && pesan[i].ukuran <= 354) {
            harga = 53000;
        } else if (pesan[i].ukuran > 354 && pesan[i].ukuran <= 473) {
            harga = 53000;
        } else if (pesan[i].ukuran > 473 && pesan[i].ukuran <= 591) {
            harga = 57000;
        } else if (pesan[i].ukuran > 591 && pesan[i].ukuran < 700) {
            harga = 60000;
        }
        else if (pesan[i].ukuran > 700 && pesan[i].ukuran < 1000) {
            harga = 70000;
        }
		else{
			printf("Error\n");
			continue;
		}
		printf("%s - %d\n", pesan[i].nama, harga);
	}
	return 0;
}
