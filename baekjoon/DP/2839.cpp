#include<cstdio>
int N, sum, i, dp[5001];
int min(int a, int b){
    if(a<b)
        return a;
    else
        return b;

}

int main(){
    //초기화
    for(i=0;i<=5000;i++)
        dp[i]=5001;
    
    scanf("%d", &N);
    dp[3]=1;
    dp[5]=1;
    for(i=6;i<=N;i++){
        dp[i]=min(dp[i-3],dp[i-5])+1;
    }
    
    if(dp[N]>=N)
        sum =-1;
    else
        sum=dp[N];
    printf("%d",sum);
    return 0;
}