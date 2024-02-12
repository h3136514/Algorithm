#include<cstdio>
int N, cnt, i;

int main(){
    scanf("%d", &N);
    cnt = 2;
    while(N--)
        cnt += cnt-1;
    printf("%d\n", cnt * cnt);
    return 0;
}