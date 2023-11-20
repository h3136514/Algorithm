#include<cstdio>
#include<algorithm>
using namespace std;

int i, N, M, num, mid, A[100000];
//이분탐색
int b(int v, int start, int end){
    while(start<=end){
        mid=(start+end)/2;
        if(A[mid]==v)
            return 1;
        else if(A[mid]>v)
            end=mid-1;
        else
            start=mid+1;
    }
    return 0;

}
int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++)
        scanf("%d", &A[i]);
    sort(A, A+N); //정렬

    scanf("%d", &M);
    for(i=0;i<M;i++){
        scanf("%d", &num);
        printf("%d\n",b(num, 0, N-1));
    }
    
    return 0;
}