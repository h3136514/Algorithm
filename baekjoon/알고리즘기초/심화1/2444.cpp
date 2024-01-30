#include<cstdio>
int N, i, j;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        for(j=i;j<N-1;j++)
            printf(" ");
        for(j=0;j<i*2+1;j++)
            printf("*");
        printf("\n");
    }
    for(i=N-2;i>=0;i--){
        for(j=i;j<N-1;j++)
            printf(" ");
        for(j=0;j<i*2+1;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}