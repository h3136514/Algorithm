#include<cstdio>
int N, i, sum=0;
char c[101];

int main(){
    scanf("%d", &N);
    scanf("%s", &c);
    for(i=0;i<N;i++){
        sum +=c[i] -'0';
    }
    printf("%d\n", sum);
    return 0;
}