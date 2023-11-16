#include<cstdio>
int T, i, L, U, X, r[1001];

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d %d %d", &L, &U, &X);
        if(L<=X && X<=U)
            r[i]=0;
        else if(L>X)
            r[i]=L-X;
        else
            r[i] =-1;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n",i, r[i]);
    }
    return 0;
}
