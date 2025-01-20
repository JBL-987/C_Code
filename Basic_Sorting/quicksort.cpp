#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char *nama;
	int tinggi;
} Orang;

void swap(Orang *a, Orang *b){
	Orang temp = *a;
	*a = *b;
	*b = temp;
}

int partition(Orang *orang, int low, int high){
	int pivot = orang[high].tinggi;
	int left = low;
	int right = high - 1;
	while (left <= right){
		while (left <= right && orang[left].tinggi < pivot){
			left++;
		}
		while (left <= right && orang[right].tinggi >= pivot){
			right--;
		}
		if (left <= right){
			swap(&orang[left], &orang[right]);
		}
	}
	swap(&orang[left], &orang[high]);
	return right;
}

void quicksort(Orang *orang, int low, int high){
	if(low < high){
		int p = partition(orang, low, high);
		quicksort(orang, low, p - 1);
		quicksort(orang, p + 1, high);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	Orang *orang = (Orang*)malloc(n * sizeof(Orang));
	if (orang == NULL){
		printf("Cannot be Null please try again");
		return 1;
	}
	for (int i = 0; i < n; i++){
		orang[i].nama = (char*)malloc(100 * sizeof(char));
		if (orang[i].nama == NULL){
		printf("Cannot be Null please try again");
		return 1;
		}
		scanf("%[^#]#%d", orang[i].nama, &orang[i].tinggi);
		getchar();
	}
	
	quicksort(orang, 0, n - 1);
	
	for (int i = 0; i < n; i++){
		printf("%s - %d\n",  orang[i].nama, orang[i].tinggi);
		free(orang[i].nama);
	}
	
	free(orang);
	return 0;
}
