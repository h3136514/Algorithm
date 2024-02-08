#include<cstdio>
int N, i, j, k, x, y, paper[101][101], sum;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d %d", &x, &y);
        for(j=x;j<x+10;j++){
            for(k=y;k<y+10;k++)
                paper[j][k] = 1;
        }
    }
    for(i=0;i<101;i++){
        for(j=0;j<101;j++)
                sum +=paper[i][j];
    }
    
    printf("%d\n", sum);
    return 0;
}