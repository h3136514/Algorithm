#include<cstdio>
int N, i, j;

int main() {
    scanf("%d", &N);
    for(i=1;i<=N;i++){
        for(j=i;j<N;j++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}