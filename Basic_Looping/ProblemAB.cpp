#include <stdio.h>

int gcd(int a, int b){
	if (b == 0){
		return a;
	}
	return gcd(b, a % b);
}

int lcm(int a, int b){
	return a / gcd(a, b) * b;
}

int count_multiples(int N, int A, int B, int C, int D) {
    int countA = N / A;
    int countB = N / B;
    int countC = N / C;
    int countD = N / D;
    
    int countAB = N / lcm(A, B);
    int countAC = N / lcm(A, C);
    int countAD = N / lcm(A, D);
    int countBC = N / lcm(B, C);
    int countBD = N / lcm(B, D);
    int countCD = N / lcm(C, D);
    
    int countABC = N / lcm(A, lcm(B, C));
    int countABD = N / lcm(A, lcm(B, D));
    int countACD = N / lcm(A, lcm(C, D));
    int countBCD = N / lcm(B, lcm(C, D));
    
    int countABCD = N / lcm(A, lcm(B, lcm(C, D)));
    
    // Inclusion-Exclusion Principle
    return countA + countB + countC + countD
           - countAB - countAC - countAD - countBC - countBD - countCD
           + countABC + countABD + countACD + countBCD
           - countABCD;
}

int main(){
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int N, A, B, C, D;
		scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);
		
		int result = count_multiples(N, A, B, C, D);
		printf("Case #%d: %d\n",i + 1, result);
	}
	return 0;
}
