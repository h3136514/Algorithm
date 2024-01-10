#include<cstdio>
int N, sum;
int main(){
    scanf("%d", &N);
    sum =N/5 + N/25+ N/125;
    printf("%d\n",sum);

    return 0;
}