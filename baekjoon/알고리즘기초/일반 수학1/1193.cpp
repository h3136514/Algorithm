#include<cstdio>
int N, i = 1;

int main(){
    scanf("%d", &N);
    while( N > i){
        N-=i;
        i++;
    }
    if( i % 2 ==1)
        printf("%d/%d\n", i+1-N, N);
    else
        printf("%d/%d\n", N, i+1-N);
        
    return 0;
}