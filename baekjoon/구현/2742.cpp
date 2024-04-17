#include<cstdio>
int num, i, N[46];

int main() {
    scanf("%d", &num);
    N[0]=0;
    N[1]=1;
    for(i=2; i<=num; i++) {
      N[i] = N[i-1] + N[i-2];
    }
    
    printf("%d\n", N[num]);
    return 0;
}