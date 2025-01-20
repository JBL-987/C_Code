#include <stdio.h>
int main() {
    int T;
    int Vocal = 0;
    int Nonvocal = 0;
    int Symbols = 0;
    int Number = 0;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        char S;
        scanf("%c", &S);
        for (int j = 1; j <= S; j++) {
            if (S >= '0' && S <= '9') {
                Number++;     
            }
             else if(S == 'a' ||  S == 'e' || S == 'i' || S == 'o' || S == 'u') {
                Vocal++;
            }
            else if(S != 'a' && S != 'e' && S != 'i' && S != 'o' && S != 'u') {
                Nonvocal++;
                }
            else if(S == '!' || S == '@' || S == '#' || S == '$' || S == '%' || 
    S == '^' || S == '&' || S == '*' || S == '(' || S == ')' || 
    S == '-' || S == '+' || S == ',' || S == '_' || S == '=' || 
    S == '<' || S == '>' || S == '/' || S == '[' || S == ']') {
    Symbols++;
    } 
    printf("Case #i:%d %d %d %d\n", Vocal, Nonvocal, Symbols, Number); 
        }
    }
    return 0;
}