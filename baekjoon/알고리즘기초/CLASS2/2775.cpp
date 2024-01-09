#include<cstdio>

int T, i, j, l, k, n, dp[15][15];
int main(){
    scanf("%d", &T);
    for(i=1;i<15;i++)
        dp[0][i]=i;
    for(i=1;i<15;i++){
        for(j=1;j<15;j++){
            for(l=1;l<=j;l++)
                dp[i][j] +=dp[i-1][l];
        }
    }
    for(i=0;i<T;i++){
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n",dp[k][n]);
    }
    return 0;
}