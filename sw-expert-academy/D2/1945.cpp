#include<cstdio>
int T, i, j, N, a[11], b[11], c[11], d[11], e[11];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        while(true){
            if(N==0 || N==1) 
                break;
            if(N%2==0){
                a[i]++;
                N=N/2;
            }
            if(N%3==0){
                b[i]++;
                N=N/3;
            }
            if(N%5==0){
                c[i]++;
                N=N/5;
            }
            if(N%7==0){
                d[i]++;
                N=N/7;
            }
            if(N%11==0){
                e[i]++;
                N=N/11;
            }
        }
    }
    for(i=1;i<=T;i++){
        printf("#%d %d %d %d %d %d\n",i ,a[i], b[i], c[i], d[i], e[i]);
    }
    return 0;
}