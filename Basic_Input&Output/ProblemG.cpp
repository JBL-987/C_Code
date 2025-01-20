#include <stdio.h>
int main(){
	char s[100];
	scanf("%[^\n]s", s);
	printf("Happy Birthday to %s.\n", s);
	return 0;
}
