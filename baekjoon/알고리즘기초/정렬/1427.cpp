#include<cstdio>
#include<algorithm>
using namespace std;
int num[10], cnt, N, i;

int main(){
    scanf("%d\n", &N);
    while(N>0){
        num[cnt] = N%10;
        N = N/10; 
        cnt++;
    }
    sort(num, num + cnt);
    for(i=cnt-1;i>=0;i--)
        printf("%d", num[i]);
    return 0;
}
