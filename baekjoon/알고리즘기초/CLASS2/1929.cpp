#include<cstdio>
#include<cmath>
int M, N, i, j, num[1000001];

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
    for(i = M; i<= N; i++){
        if(!num[i])
            printf("%d\n", i);       
    }
   
    return 0;
}