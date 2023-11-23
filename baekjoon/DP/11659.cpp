#include<cstdio>
int N, M, i, num, a, b, dp[100001];
int main(){
    scanf("%d %d", &N, &M);
    
    for(i=1;i<=N;i++){
        scanf("%d", &num);
        dp[i]=dp[i-1]+num;
    }
    //출력
    for(i=0;i<M;i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[b]-dp[a-1]);
    }
    return 0;
}