#include<cstdio>
#include <algorithm>
using namespace std;
int A[51], B[51], N, i, sum;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++)
        scanf("%d", &A[i]);
    sort(A, A+N);
    for(i=0;i<N;i++)
        scanf("%d", &B[i]);
    sort(B, B+N);
    for(i=0;i<N;i++)
        sum += A[i]*B[N-1-i];
    printf("%d\n", sum);
}