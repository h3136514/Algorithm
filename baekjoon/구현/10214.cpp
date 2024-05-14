#include<cstdio>
int Y, K, sumY, sumK, i, T;

int main() {
    scanf("%d", &T);
    while(0 < T--){
        sumY = 0;
        sumK = 0;
        for(i=0;i<9;i++){
            scanf("%d %d", &Y, &K);
            sumY += Y;
            sumK += K;
        }
        if(sumY > sumK)
            printf("Yonsei\n");
        else if(sumY < sumK)
            printf("Korea\n");
        else
            printf("Draw\n");
    }
    
    return 0;
}