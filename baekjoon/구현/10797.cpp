#include<cstdio>
int N, num, sum, i;

int main() {
    scanf("%d", &N);
    for(i=0;i<5;i++) {
        scanf("%d", &num);
        if(N == num)
            sum++;
    }
    printf("%d\n", sum);
    
    return 0;
}