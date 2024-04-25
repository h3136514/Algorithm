#include<cstdio>
int A, B, dp[1001], i, j, cnt;

int main() {
    cnt=1;
    for(i=1;i<=1000;i++) {
        if(cnt >1000)
            break;
        for(j=1;j<=i;j++) {
            if(cnt >1000)
                break;
            dp[cnt] = dp[cnt-1] +i;
            cnt++; 
        }

    }
    scanf("%d %d", &A, &B);
    printf("%d\n", dp[B] -  dp[A-1]);
    return 0;
}