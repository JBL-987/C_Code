#include <stdio.h>
#include <cstdio>     
#include <cstring>

int main(){
	
	char S[100];
	// Use fgets to read a line of input, including spaces.
    fgets(S, sizeof(S), stdin);
    
    // Remove the newline character that fgets captures at the end of the input
    S[strcspn(S, "\n")] = 0;
	printf("Congrats \"%s\" for joining the CS department at BINUS.\n", S);
	return 0;
}
