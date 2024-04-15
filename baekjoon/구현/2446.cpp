#include<cstdio>
int N, i, j;

int main() {
    scanf("%d", &N);
    for(i=N;i>0;i--){
        for(j=i;j<N;j++)
            printf(" ");
        for(j=1;j<=2*i-1;j++)
            printf("*");
        printf("\n");
    }
    for(i=2;i<=N;i++){
        for(j=i;j<N;j++)
            printf(" ");
        for(j=1;j<=2*i-1;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}