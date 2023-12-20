#include<cstdio>
int N, i, j, num, sum;
//소수 판별
bool minority(int n){
    if(n == 1)
        return false;

    for(j=2;j<n;j++){
        if(n%j == 0)
            return false;
    }
    return true;
}

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &num);
        if(minority(num))
            sum++;
    }
    printf("%d", sum);
    return 0;
}