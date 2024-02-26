#include<cstdio>
#include <algorithm>
using namespace std;
int num[1001], N, i;

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++)
        scanf("%d", &num[i]);
    sort(num, num+N);
    for(i=0;i<N;i++)
        printf("%d\n", num[i]);

}