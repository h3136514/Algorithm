#include<cstdio>
int N, num, dp[11], i;
int main(){
    scanf("%d", &N);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(i=4;i<11;i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    
    for(i=0;i<N;i++){
        scanf("%d", &num);
        printf("%d\n", dp[num]);
    }
    return 0;
}