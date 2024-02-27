#include<cstdio>
int numx, numy, x[1001], y[1001], i;

int main(){
    for(i=0 ;i<3;i++){
        scanf("%d %d", &numx, &numy);
        if(x[numx])
            x[numx] = 0;
        else
            x[numx] = 1;
        if(y[numy])
            y[numy] = 0;
        else
            y[numy] = 1;
    }
    for(i=1 ;i<=1000; i++){
        if(x[i])
            numx = i;
        if(y[i])
            numy = i;
    }
    printf("%d %d\n", numx, numy);
    return 0;
}