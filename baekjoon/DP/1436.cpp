#include<cstdio>

int N, i, dp[1000001];
int min(int a, int b){
    if(a>b)
        return b;
    else
        return a;
}
int main(){
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    scanf("%d",&N);
    for(i=4;i<=N;i++){
        dp[i]=dp[i-1]+1;
        if(i%3==0)
            dp[i]=min(dp[i],dp[i/3]+1);
        if(i%2==0)
            dp[i]=min(dp[i],dp[i/2]+1);
    }
    printf("%d",dp[N]);
    return 0;
}

