#include<cstdio>
int N, M, i, j, k, l, z, num[101];

int main(){
    scanf("%d %d", &N, &M);
    for(l=0;l<M;l++){
        scanf("%d %d %d", &i, &j, &k);
        for(z=i;z<=j;z++)
            num[z] = k;
    }
    for(l=1;l<=N;l++){
        printf("%d ", num[l]);
    }
    printf("\n");
    return 0;
}