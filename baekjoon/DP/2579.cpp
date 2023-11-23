#include<cstdio>
int N, i, input[301], dp[301][3];
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
int stair(int p,int k){
    if(p==N)    //도착지
        return input[p];
    if(p>N)     //도착지를 넘엇을 때
        return -1000000;    //도태 되게 
    if(dp[p][k])
        return dp[p][k];
    
    if(k<2) //연속된 세 개의 계단 못밟음
        return dp[p][k]=max(stair(p+1, k+1), stair(p+2, 1)) +input[p];

    return dp[p][k]=stair(p+2, 1)+input[p];
}   

int main(){
    scanf("%d", &N);
    for(i=1;i<=N;i++)
        scanf("%d",&input[i]);
    printf("%d ", stair(0,0));
    return 0;
}