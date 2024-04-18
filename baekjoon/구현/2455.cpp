#include<cstdio>
int i, a, b, sum, max;

int main() {
    for(i=0;i<4;i++) {
        scanf("%d %d", &a, &b);
        sum +=(-a+b);
        if(sum > max)
            max = sum;
        }
    printf("%d\n",max);
    return 0;
}