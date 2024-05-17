#include<cstdio>
int N, a, b, suma, sumb, i;

int main() {
    scanf("%d", &N);
    suma = 100;
    sumb = 100;
    for(i=1;i<=N;i++){
        scanf("%d %d", &a, &b);
        if(a > b)
            sumb -= a;
        else if(a < b)
            suma -= b;
    }
    printf("%d\n", suma);
    printf("%d\n", sumb);

    return 0;
}