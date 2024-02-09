#include<cstdio>
int N, C, Q, D, Ni, P, i;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        Q = 0;
        D = 0;
        Ni = 0;
        P = 0;
        scanf("%d", &C);
        if(C>=25){
            Q = C/25;
            C = C%25;
        }
        if(C>=10){
            D = C/10;
            C = C%10;
        }
        if(C>=5){
            Ni = C/5;
            C = C%5;
        }
        P = C;
        printf("%d %d %d %d\n", Q, D, Ni, P);
    }
    
    return 0;
}