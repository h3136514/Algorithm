#include<cstdio>

int T, N, i, j, k, tmp, sum[11], num[100][100];

int main(){
    T=10;
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        for(j=0;j<100;j++){
            for(k=0;k<100;k++){
                scanf("%d", &num[j][k]);
            }
        }
        //가로줄 계산
        for(j=0;j<100;j++){
            tmp=0;
            for(k=0;k<100;k++)
                tmp+=num[j][k];
            if(sum[i]<tmp)
                sum[i]=tmp;
        }
        //세로줄 계산
        for(j=0;j<100;j++){
            tmp=0;
            for(k=0;k<100;k++)
                tmp+=num[k][j];
            if(sum[i]<tmp)
                sum[i]=tmp;
        }
        tmp=0;
        //대각선줄 계산
        for(j=0;j<100;j++)
            tmp+=num[j][j];
        if(sum[i]<tmp)
            sum[i]=tmp;
        tmp=0;
        for(j=0;j<100;j++)
            tmp+=num[j][99-j];
        if(sum[i]<tmp)
            sum[i]=tmp;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i,sum[i]);
    }

    return 0;
}