#include<cstdio>
int T, i, j, k, N, M, V1, V2, sum, max[11], A[20], B[20];

int main(){
    scanf("%d", &T);
    for(k=1;k<=T;k++){
        scanf("%d", &N);
        scanf("%d", &M);
        for(i=0;i<N;i++)
            scanf("%d", &A[i]);
        for(j=0;j<M;j++)
            scanf("%d", &B[j]);
        if(N>M){
            V1=N;
            V2=M;
        }
        else{
            V1=M;
            V2=N;
        }
            
        for(i=0;i<=V1-V2;i++){
            sum=0;
            for(j=i;j<V2+i;j++){
                if(N>M)
                    sum+=A[j]*B[j-i];
                else
                    sum+=A[j-i]*B[j];
            }
            if(max[k] < sum)
                max[k] = sum;
        }
    }
     for(k=1;k<=T;k++){
            printf("#%d %d\n",k, max[k]);
        }
    return 0;
}