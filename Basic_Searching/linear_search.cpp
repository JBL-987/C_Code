#include <stdio.h>

int linear_search(int n, int key,int *arr){
	for (int i = 0; i < n; i++){
		if (arr[i] == key){
			return i;
		}
	}
	return -1;
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	int key;
	scanf("%d", &key);
    getchar();
	int arr[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		getchar();
	}
	int result = linear_search(n, key, arr);  // your linear search result as a variable
    if (result != -1) {
        printf("Element found at index %d\n", result);  // if the index is found
    } else {
        printf("Element not found\n");  // if the index is not found
    }
	return 0;
}
