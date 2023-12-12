#include<cstdio>
int T, A, B, i, sum;

int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d %d", &A, &B);
        sum=A+B;
        printf("Case #%d: %d\n", i, sum);
    }
    
    return 0;
}