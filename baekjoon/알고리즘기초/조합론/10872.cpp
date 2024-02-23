#include<cstdio>
int i, N, sum;

int main(){
    scanf("%d", &N);
    sum=1;
    for(i=2;i<=N;i++)
        sum = sum*i;

    printf("%d\n",sum);
    return 0;
}