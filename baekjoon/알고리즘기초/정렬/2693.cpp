#include<cstdio>
#include<algorithm>
using namespace std;
int num[10], N, i, j;

int main(){
    scanf("%d", &N);
    for(j=0;j<N;j++){
        for(i=0;i<10;i++)
            scanf("%d", &num[i]);
        sort(num, num + 10);
        printf("%d\n", num[7]);
    }
    return 0;
}
