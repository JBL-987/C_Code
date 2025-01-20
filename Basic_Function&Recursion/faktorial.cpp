#include <stdio.h>
//fibo
int fibo(int n){
	if (n == 0){
		return 0;
	}
	else if (n == 1 || n ==2){
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}

//faktorial

int factorial(int n){
	if ( n == 0 || n == 1){
		return 1;
	}
	else if (n == 2){
		return 2;
	}
	return n * factorial(n - 1);
}

int the_biggest(int *arr){
    int max = arr[0]; 
    for (int i = 1; i < 5; i++) { 
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	int arr[5] = {2, 9, 3, 7, 5};
	for (int i = 0; i < n; i++){
		printf("%d ", fibo(i));
	}
	printf("\n");
	printf("%d", factorial(n));
	printf("The biggest number in the array is: %d\n", the_biggest(arr));
	return 0;
}



