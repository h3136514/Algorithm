#include<cstdio>

int T, i, N, wona[11], wonb[11], wonc[11], wond[11], wone[11], wonf[11], wong[11], wonh[11];

void machine(int N){
    wona[i] =N/50000;
    N=N%50000;
    wonb[i] =N/10000;
    N=N%10000;
    wonc[i] =N/5000;
    N=N%5000;
    wond[i] =N/1000;
    N=N%1000;
    wone[i] =N/500;
    N=N%500;
    wonf[i] =N/100;
    N=N%100;
    wong[i] =N/50;
    N=N%50;
    wonh[i] =N/10;
    N=N%10;
}
int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        machine(N);
    }
    for(i=1;i<=T;i++){
        printf("#%d\n",i);
        printf("%d %d %d %d %d %d %d %d\n",wona[i],wonb[i],wonc[i], wond[i], wone[i], wonf[i], wong[i], wonh[i]);
    }
    return 0;
}