#include<cstdio>
int T, N, num, i, j, sum;

int main() {
    
    scanf("%d", &T);

    for(i=0;i<T;i++){
        scanf("%d", &N);
        sum = 0;
        for(j=0;j<N;j++){
            scanf("%d", &num);
            sum += num;
        }
        printf("%d\n", sum);
    }

    return 0;
}