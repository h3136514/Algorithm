#include<cstdio>
int N, i;
double M, sum, num[1001];

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%lf", &num[i]);
        if(M < num[i])
            M = num[i];
    }
    for(i=0;i<N;i++){
        sum += num[i]/M*100;
    }
    printf("%lf\n",sum/N);
    return 0;
}