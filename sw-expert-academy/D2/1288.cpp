#include<cstdio>
int T, i, j ,k, a, b, N, V, count, num[10], result[11];
void init(){
    count=0;
    V=0;
    j=0;
    for(k=0;k<10;k++)
        num[k]=0;
}
int main(){
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        scanf("%d", &N);
        init();
        while(true){
            j++;
            count++;
            a = N*j;
            while(a>0){
                b=a%10;
                a=a/10;
                if(num[b]==1)
                    continue;
                else{
                    num[b]=1;
                    V++;
                }
            }
            if(V>=10)
                break;
        }
        result[i]=count*N;
    }
    for(i=1;i<=T;i++){
        printf("#%d %d\n", i, result[i]);
    }
    return 0;
}