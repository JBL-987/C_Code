#include <stdio.h>
int main(){
	int n;
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m + 1; i++){
		printf("%d\n", n++);
	}
	return 0;
}
