#include<cstdio>
int N, N2,i, sum;

int main(){
    scanf("%d", &N);
    sum=N;
    for(i=1;i<N;i++){
        N2=i;
        sum=N2;
        while(N2>0){
            sum+=N2%10;
            N2 /=10; 
        }
        if(sum==N){
            break;
        }
            
    }
    if(i==N)
        printf("0\n");
    else
        printf("%d\n",i);
    return 0;
}