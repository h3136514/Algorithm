#include<cstdio>

int T, i, j, N, a, b, result[11];

int main(){
    T=10;
    for(i=1;i<=10;i++){
        result[i]=1;
        scanf("%d",&N);
        scanf("%d %d",&a, &b);
        for(j=0;j<b;j++)
            result[i]*=a;
    }
    for(i=1;i<=10;i++){
        printf("#%d %d\n",i, result[i]);
    }
    return 0;
}