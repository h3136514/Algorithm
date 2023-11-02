#include<cstdio>

int N, i, j, num, sum[10001];

int main(){
    scanf("%d",&N);
    for(i=1;i<=N;i++){
        for(j=0;j<10;j++){
            scanf("%d",&num);
            if(num%2==0)
                continue;
            sum[i] +=num;
        }
    }
    for(i=1;i<=N;i++){
        printf("#%d %d\n",i,sum[i]);
    }
    return 0;
}