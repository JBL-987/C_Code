#include <stdio.h>
int main(){
	int n;
	int m;
	scanf("%d %d", &n, &m);
	while (m > 0){
		printf("%d\n", n++);
		m--;
	}
	return 0;
}
