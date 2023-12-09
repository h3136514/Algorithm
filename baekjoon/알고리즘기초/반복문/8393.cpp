#include<cstdio>
int i, n, sum;

int main(){
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        sum +=i;
    }
    printf("%d", sum);
    return 0;
}