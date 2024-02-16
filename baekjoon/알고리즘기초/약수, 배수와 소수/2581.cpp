#include<cstdio>
#include<cmath>
int M, N, i, j, sum, min, num[10001];

//에라토스테네스의 체
void primeNumber(int n){
    num[1]=1;
    for(i = 2; i<= sqrt(n); i++){
        if(num[i])
            continue;
        for(j = i+i; j<= n; j+=i){
            if(num[j])
                continue;
            num[j] = 1;  
        }
    }
}

int main(){
    scanf("%d %d", &M, &N);
    primeNumber(N);
    sum=0;
    for(i = M; i<= N; i++){
        if(!num[i]){
            if(!sum)
                min = i;
            sum +=i;
        }   
    }
    if(!sum){
        printf("-1\n");
        return 0;
    }
    printf("%d\n", sum);
    printf("%d\n", min);
    return 0;
}