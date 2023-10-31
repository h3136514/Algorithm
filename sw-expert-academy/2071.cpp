#include<cstdio>
#include<cmath>     //round()를 쓰기위해

int T, i, j, num, sum[10001];
int main(){
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        while(j < 10){
            scanf("%d",&num);
            sum[i] +=num;
            j++;
        }
        sum[i] =  round(sum[i]/10.0);   //반올림
        j=0;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i, sum[i]);
    }
    return 0;
}