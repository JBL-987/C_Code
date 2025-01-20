#include <stdio.h>

int fib(int n){
    if (n <= 1) return n; 
    return fib(n-1) + fib(n-2); 
}

int main(){
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        int n;
        scanf("%d", &n);
        int result = fib(n) + fib(n-1) + 1; 
        result = (fib(n-1) * 2) + fib(n); 
        printf("Case #%d: %d\n", i + 1, result);
    }
    return 0;
}
