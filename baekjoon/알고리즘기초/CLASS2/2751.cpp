#include<cstdio>
#include<algorithm>
using namespace std;
int N, i, num[1000001];

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &num[i]);
    }
    sort(num, num + N);
    for(i=0;i<N;i++)
        printf("%d\n", num[i]);
    return 0;
}