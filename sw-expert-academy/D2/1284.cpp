#include<cstdio>
int T, i, P, Q, R, S, W, price[8];

int main(){
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d %d %d %d",&P, &Q, &R, &S, &W);
        if(R>=W)
        {
            if(Q > P*W )
                price[i] =P*W;
            else
                price[i] =Q;
        }else{
            if((S*(W-R) + Q) > P*W )
                price[i] =P*W;
            else
                price[i] =S*(W-R) + Q;
        }
    }
    for(i=1; i<=T; i++){
        printf("#%d %d\n", i, price[i]);
    }
    return 0;
}