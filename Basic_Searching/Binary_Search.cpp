#include <stdio.h>

int binary_search(int n, int *arr, int key){
	int low = 1; //starting index
	int high = n - 1; //last index
	while ( low <= high ){
		int mid = (low + high) / 2;
		if (arr[mid] == key){
			while (mid > 1 && arr[mid - 1] == key){
				return mid--;
			}
			return mid++;
		}
		else if (arr[mid] < key){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return -1;
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
	
	int key;
	scanf("%d", &key);
	getchar();
	
	printf("%d\n", binary_search(n, arr, key));
	return 0;
}
