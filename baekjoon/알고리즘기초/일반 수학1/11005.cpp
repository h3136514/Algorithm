#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int B, sum, t, cnt=0;
char N[30];

int main(){
    scanf("%d %d",&sum, &B);
    while(sum>0){
        t = sum%B;
        N[cnt++] = t< 10 ? t + '0' : t - 10 + 'A';
        sum /= B;
    
    }
    for(int i=cnt-1;i>=0;i--){
        printf("%c", N[i]);
    }
    return 0;
}