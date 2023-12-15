#include<cstdio>
int N, i, cnt, check[43];

int main(){
    for(i=0;i<10;i++){
        scanf("%d", &N);
        N = N%42;
        if(check[N])
            continue;
        else{
            check[N] = 1;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}