#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	int arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		getchar();
	}
	
	qsort(arr, n, sizeof(int), compare);
	
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
