#include<cstdio>
#include <algorithm>
using namespace std;
int A[2], B[5], N, i, j, tmp,sum;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        for(j=0;j<2;j++){
            scanf("%d", &A[j]);
        }
        for(j=0;j<5;j++){
            scanf("%d", &B[j]);
        }
        sort(A, A+2);
        sort(B, B+5);
        tmp = A[1] + B[3] + B[4];
        if(sum < tmp)
            sum =tmp;
    }
    printf("%d\n", sum);
}