#include<cstdio>
int N, K, i, num;

int factorial(int num){
    if(num==0) return 1;
    int r=1;
    for(i=num;i>0;i--){
        r *=i;
    }
    return r;
}

int main(){
    scanf("%d %d", &N, &K);
    printf("%d\n",factorial(N)/(factorial(K)*factorial(N-K)));
    return 0;
}