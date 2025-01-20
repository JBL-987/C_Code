#include <stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	int a, b, c;
	for (int i = 0; i < t; i++){
		scanf("%d %d %d", &a, &b, &c);
		int d = a * b/100;
		if (d >= c){
		printf("Case #%d: %d\n", i + 1, c);	
		}
		else {
			printf("Case #%d: %d\n", i + 1, d);
		}
	}
	return 0;
}
