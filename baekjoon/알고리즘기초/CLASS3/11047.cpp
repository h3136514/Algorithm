#include<cstdio>
int N, K, i, num[10], sum;

int main(){
    scanf("%d %d", &N, &K);
    for(i=0;i<N;i++){
        scanf("%d", &num[i]);
    }
    for(i=N-1;i>=0;i--){
        if(K/num[i] > 0){
            sum +=K/num[i];
            K=K%num[i];
        }
        if(K==0)
            break;
    }
    printf("%d\n", sum);
    return 0;
}