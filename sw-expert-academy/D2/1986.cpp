#include<cstdio>
int T, i, j, N, sum[11];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        for(j=1;j<=N;j++){
            if(j%2==0)
                sum[i] -=j;
            else
                sum[i] +=j;
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n", i, sum[i]);
    }
    return 0;
}