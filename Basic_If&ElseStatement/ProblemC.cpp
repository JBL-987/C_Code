#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	int a, b;
	for (int i = 1; i <= t; i++){
		scanf("%d %d", &a, &b);
		if (i % 2 == 0){
			printf("Case #%d: Bi-Pay\n", i);
		}
		else{
			printf("Case #%d: Go-Jo\n", i);
		}
	}
	return 0;
}
