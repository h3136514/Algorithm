#include<cstdio>
int A, B, C, n, i, sum, num[10];

int main(){
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    sum = A*B*C;
    while(sum>0){
        n = sum%10;
        num[n]++;
        sum /= 10;
    }
    for(i=0;i<10;i++)
        printf("%d\n", num[i]);
        
    return 0;
}