#include<cstdio>
#include<algorithm>
using namespace std;
int num[1001], i, N, target;

int main(){
    scanf("%d %d", &N, &target);
    for(i=0; i<N; i++){
        scanf("%d", &num[i]);
    }
    sort(num, num+N);
    printf("%d\n", num[N-target]);
    return 0;
}