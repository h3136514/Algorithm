#include<cstdio>
int T, i, j, N, a, b, sum, r[577];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d %d", &a, &b);
        sum=a+b;
        if(sum>=24)
            sum=sum-24;
        r[i]=sum;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i,r[i]);
    }
    return 0;
}