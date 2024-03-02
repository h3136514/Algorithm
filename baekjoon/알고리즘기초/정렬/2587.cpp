#include<cstdio>
#include<algorithm>
using namespace std;
int num[5], i, avg;

int main(){
    for(i=0; i<5; i++){
        scanf("%d", &num[i]);
        avg += num[i];
    }
    sort(num, num+5);
    printf("%d\n", avg/5);
    printf("%d\n", num[2]);
    return 0;
}