#include<cstdio>
int N, i, dp[21];

int main() {
    dp[0] = 0;
    dp[1] = 1;

    scanf("%d", &N);
    for(i=2;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    printf("%d\n", dp[N]);
    return 0;
}