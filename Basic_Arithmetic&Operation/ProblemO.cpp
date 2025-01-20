#include <stdio.h>
int main(){
	long long int x;
	long long int y;
	for (int i = 0; i < 4; i++){
		scanf("%d %d", &x, &y);
		long long int total = x * y;
	    printf("%d\n", total);
	}
	return 0;
}
