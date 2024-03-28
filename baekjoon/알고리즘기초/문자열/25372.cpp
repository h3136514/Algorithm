#include<cstdio>
#include<algorithm>
using namespace std;
int N, i, j, dp[50001];

int main() {
    scanf("%d", &N);
    for(i=1;i<=N;i++){
        dp[i] = dp[i-1] +1;
        for(j=1; j*j <=i;j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    printf("%d\n", dp[N]);
    return 0;
}