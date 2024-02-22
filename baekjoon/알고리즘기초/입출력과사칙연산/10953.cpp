#include<cstdio>
int A, B, N, i;
char str[4];

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%s", &str);
        A = str[0] -'0';
        B = str[2] -'0';
        printf("%d\n", A+B);
    }
    return 0;
}