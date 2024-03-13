#include<cstdio>
#include<algorithm>
using namespace std;
int W[10], K[10], Wsum, Ksum, i;

int main(){
    for(i=0; i<10; i++){
        scanf("%d", &W[i]);
    }
    for(i=0; i<10; i++){
        scanf("%d", &K[i]);
    }
    sort(W, W+10);
    sort(K, K+10);
    Wsum = W[7]+ W[8] +W[9];
    Ksum = K[7]+ K[8] +K[9];
    printf("%d %d\n", Wsum, Ksum);
    
    return 0;
}