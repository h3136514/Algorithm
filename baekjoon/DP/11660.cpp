#include<cstdio>

int N, M, i, j, x1,y1,x2,y2, dp[1025][1025],num[1025][1025],sum;
int dpnum(int x1,int y1,int x2, int y2){
    if(x1==x2 && y1==y2)
        return num[x1][y1];
    
    return dp[x2][y2]- dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];    //연속된 공간 때문에 dp[x1-1][y1-1]를 더함
}

int main(){
    scanf("%d %d", &N, &M);
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            scanf("%d", &num[i][j]);
        }
    }
    //누적합 구하기
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++)
            dp[i][j]=dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num[i][j];
    }
    //출력
    for(i=1;i<=M;i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        sum=dpnum(x1,y1,x2,y2);
        printf("%d\n",sum);
    }
    return 0;
}