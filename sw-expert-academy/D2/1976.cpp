#include<cstdio>
int T, N, i, h1, m1, h2, m2, sumh, summ, h[11], m[11];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        sumh=0;
        summ=0;
        if((m1+m2)>59){
            summ= m1 + m2 - 60;
            sumh++;
        }
        else
            summ= m1+m2;
        if((h1+h2+sumh)>12){
            sumh = h1+ h2 + sumh - 12;
        }
        else
            sumh = h1 + h2 + sumh;

        h[i] = sumh;
        m[i] = summ;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d %d\n", i, h[i], m[i]);
    }
    return 0;
}