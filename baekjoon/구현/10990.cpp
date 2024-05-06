#include<cstdio>
int N, i, j;

int main() {
    scanf("%d", &N);
    for(i=1;i<=N;i++){
        for(j=i;j<N;j++)
            printf(" ");
        for(j=1;j<=i*2-1;j++){
            if(j==1 || j==i*2-1)
                printf("*");
            else
                printf(" ");
            }
        printf("\n");
    }
    return 0;
}