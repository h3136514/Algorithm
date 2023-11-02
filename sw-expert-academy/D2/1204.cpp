#include<cstdio>
int T, i,j, num, input, dp[1001], max[2][11]; //max[0][]: 최대 빈도갯수, max[1][]: 최대빈도 숫자 

int main(){
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d",&num);
        for(j=0;j<1000;j++)
        {
            scanf("%d", &input);
            dp[input]++;
        }
        for(j=1;j<=1000;j++){
            if(max[0][num] <=dp[j]){
                max[0][num] =dp[j];
                max[1][num] =j;
            }
            dp[j]=0;
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n", i,  max[1][i]);
    }
    return 0;
}