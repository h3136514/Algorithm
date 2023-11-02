#include<cstdio>
int i, num, sum;

int main(){
    scanf("%d", &num);
    for(i=1;i<=num;i++)
        sum +=i;

    printf("%d",sum);
    return 0;
}