#include <stdio.h>
#include <string.h>

#define MAX 101

typedef struct{
	char video[MAX];
	char nama[MAX];
	int views;
} Youtube;

void swap(Youtube *a, Youtube *b){
	Youtube temp = *a;
	*a = *b;
	*b = temp;
}
//descending order
int partition(Youtube *youtuber,int low, int high){
	int pivot = youtuber[high].views;
	char stringpivot[MAX];
	strcpy(stringpivot, youtuber[high].video);
	int right = high - 1;
	int left = low;
	while (left <= right){
		while ( left <= right && (youtuber[left].views >= pivot || (youtuber[left].views == pivot && strcmp(youtuber[left].video, stringpivot) < 0))){
			left++;
		}
		while  ( left <= right && (youtuber[right].views < pivot || (youtuber[right].views == pivot && strcmp(youtuber[right].video, stringpivot) >= 0))){
			right--;
		}
		if (left <= right){
			swap(&youtuber[left], &youtuber[right]);
		}
	}
	swap(&youtuber[left], &youtuber[high]);
	return left;
}

void quicksort(Youtube *youtuber,int low, int high){
	if (low < high){
		int p = partition(youtuber, low, high);
		quicksort(youtuber, low, p - 1);
		quicksort(youtuber, p + 1, high);
	}
}

int main(){
	FILE *fp;
	fp = fopen("testdata.in", "r");
	Youtube youtuber[MAX];
	int n = 0;
	if (fp == NULL){
		printf("File is empty\n");
		return 1;
	}
	while (fscanf(fp, "%[^#]#%[^#]#%d", youtuber[n].video, youtuber[n].nama, &youtuber[n].views) == 3){
		n++;
		if (n >= MAX) {
            break; 
        }
	}
	quicksort(youtuber, 0, n - 1);
	
	for (int i = 0; i < n; i++){
		    printf("%s by %s - %d",  youtuber[i].video, youtuber[i].nama, youtuber[i].views);	
	}
	
	fclose(fp);
	return 0;
}
