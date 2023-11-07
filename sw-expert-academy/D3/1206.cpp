#include<cstdio>

int T, N, i, j, max, maxL, maxR, count, result[11], num[1000];
int Max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int main(){
    T=10;
    for(i=1;i<=T;i++){
        //초기화
        for(j=0;j<N;j++){
            num[j]=0;
        }
        count=0;
        maxL=0;
        maxR=0;
        max=0;
        scanf("%d", &N);
        for(j=0;j<N;j++){
            scanf("%d", &num[j]);
        }
        for(j=0;j<N;j++){
            if(j==0){
                maxL=0;
            }else if(j==1){
                maxL=num[0];
            }
            else{
                maxL=Max(num[j-2], num[j-1]);
            }
            if(j==N-1){
                maxR=0;
            }else if(j==N-2){
                maxR=num[N-1];
            }
            else{
                maxR=Max(num[j+2], num[j+1]);
            }
            max=Max(maxL, maxR);
            if(num[j]-max<=0)
                continue;
            else
            count+=num[j]-max;
        }
        result[i] =count;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i, result[i]);
    }
    return 0;
}
