#include<cstdio>
int N, i, j, num[501][501], dp[501][501],MAX;
int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int main(){
    scanf("%d", &N);
    N;
    for(i=1;i<=N;i++){
        for(j=1;j<=i;j++){
            scanf("%d", &num[i][j]);
        }
    }
    for(i=1;i<=N;i++){
        for(j=1;j<=i;j++){
            dp[i][j]=max(dp[i-1][j], dp[i-1][j-1]) +num[i][j];
        }
    }
    for(i=1;i<=N;i++)
        if(MAX<dp[N][i])
            MAX=dp[N][i];
            
    printf("%d", MAX);
    return 0;
}