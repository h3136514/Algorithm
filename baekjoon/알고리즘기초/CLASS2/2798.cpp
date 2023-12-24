#include<cstdio>
int N, M, i, j, k, max, sum, num[101];

int main(){
    scanf("%d %d", &N, &M);
    for(i=0;i<N;i++)
        scanf("%d", &num[i]);
    for(i=0;i<N-2;i++){
        for(j=i+1;j<N-1;j++){
            for(k=j+1;k<N;k++){
                sum = num[i] + num[j] +num[k];
                if(sum > M)
                    continue;
                if(max < sum)
                    max = sum;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}