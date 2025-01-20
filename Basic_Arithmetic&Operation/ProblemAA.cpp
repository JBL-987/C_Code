#include <stdio.h>
int main(){
	double T;
	double Ut;
	double Ua;
	scanf("%lf %lf %lf", &T, &Ut, &Ua);
	printf("%.2lf\n", T*20/100 + Ut*30/100 + Ua*50/100);
	return 0;
}
