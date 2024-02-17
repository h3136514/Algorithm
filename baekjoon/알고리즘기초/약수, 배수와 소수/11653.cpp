#include<cstdio>
int N, i;

int main(){
    scanf("%d", &N);
    while(N>1){
        for(i=2;i<=N;i++){
            if(N%i == 0){
                printf("%d\n", i);
                N = N/i;
                break;
            }
        }
    }
    return 0;
}