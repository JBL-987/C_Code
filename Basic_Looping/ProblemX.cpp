#include <stdio.h>
int main(){
	int q;
	scanf("%d", &q);
	int n = 1;
	for (int i = 0; i < q; i++) {
		n = n * 2;
		n = n + 1;
	}
	printf("%d\n", n);
	return 0;
}
