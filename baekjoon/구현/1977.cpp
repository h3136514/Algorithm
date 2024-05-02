#include<cstdio>
int M, N, num, sum, min;

int main() {
    scanf("%d %d", &M, &N);
    while(num*num <= N) {
        if(num*num >= M) {
            if(!min)
                min = num*num;
            sum += num*num;
        }
        num++;
    }
    if(min) {
        printf("%d\n", sum);
        printf("%d\n", min);
    } else
        printf("-1\n");

    return 0;
}