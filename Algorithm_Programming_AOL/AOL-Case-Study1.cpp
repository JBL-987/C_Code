#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char string[101];
	scanf("%s", string);
	getchar();
	int count = strlen(string);
	for (int i = 0; i < count / 2; i++){
		if (isalpha(string[i]) && string[i] >= 'a' && string[i] <= 'z') {
			string[i] = toupper(string[i]);
		}
		else {
			string[i] = tolower(string[i]);
		}
		if (isalpha(string[count - i - 1]) && string[count - i - 1] >= 'a' && string[count - i - 1] <= 'z') {
			string[count - i - 1] = toupper(string[count - i - 1]);
		}
		else {
			string[count - i - 1] = tolower(string[count - i - 1]);
		}
		char temp = string[i];
		string[i] = string[count - i - 1];
		string[count - i - 1] = temp;
	}
	printf("%s\n", string);
	return 0;
}
