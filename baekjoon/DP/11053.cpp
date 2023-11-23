#include<cstdio>

int N, i, j, answer, num[1001], dp[1001];
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

int main(){
    scanf("%d", &N);
    for(i=1;i<=N;i++)
        scanf("%d", &num[i]);
        
    answer=0;
    for(i=1;i<=N;i++){
        dp[i]=1;
        for(j=i-1;j>=1;j--){
            if(num[i] > num[j])
                dp[i]= max(dp[i], dp[j]+1);
        }
        answer= max(dp[i], answer);
    }

    printf("%d", answer);
    return 0;
}