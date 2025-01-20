#include <stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int a;
		int b;
		scanf("%d %d", &a, &b);
		int result = (a >> b) & 1;
		printf("%d\n", result);
	}
	return 0;
}
