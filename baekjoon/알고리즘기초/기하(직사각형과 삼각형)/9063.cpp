#include<cstdio>
#include <algorithm>
using namespace std;
int numx, numy, x[100001], y[100001], N, i;

int main(){
    scanf("%d\n", &N);
     for(i=0 ;i<N;i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    sort(x, x+N);
    sort(y, y+N);
    if(N<2)
        printf("0\n");
    else
        printf("%d\n", (x[N-1]-x[0])*(y[N-1]-y[0]));
    return 0;
}