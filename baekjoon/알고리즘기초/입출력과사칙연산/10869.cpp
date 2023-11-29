#include<cstdio>
int A, B, sum, min, mult, div, rest;

int main(){
    scanf("%d %d", &A, &B);
    sum = A+B;
    min = A-B;
    mult = A*B;
    div = A/B;
    rest = A%B;
    printf("%d\n", sum);
    printf("%d\n", min);
    printf("%d\n", mult);
    printf("%d\n", div);
    printf("%d\n", rest);
    return 0;
}