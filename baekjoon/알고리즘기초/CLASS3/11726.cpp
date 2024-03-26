#include<cstdio>
int N, i, dp[1001]={1,1};

int main() {
    scanf("%d",&N);
    for(i=2; i<=N; i++)
        dp[i] = (dp[i-1] + dp[i-2])%10007;

    printf("%d\n", dp[N]);
    return 0;
}