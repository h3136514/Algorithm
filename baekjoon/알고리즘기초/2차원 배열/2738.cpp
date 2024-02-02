#include<cstdio>
int N, M, i, j, num, A[101][101], B[101][101];

int main(){
    scanf("%d %d", &N, &M);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d", &A[i][j]);
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d", &B[i][j]);
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("%d ", A[i][j]+B[i][j]);
        }
        printf("\n");
    }
    return 0;
}