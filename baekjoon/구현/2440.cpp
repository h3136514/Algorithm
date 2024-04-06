#include<cstdio>
int N, i, j;

int main() {
    scanf("%d", &N);
    for(i=0;i<N;i++){
        for(j=i;j<N;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}