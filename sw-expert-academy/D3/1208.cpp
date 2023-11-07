#include<cstdio>
#include<algorithm>
using namespace std;

int N, i, j, num[100], dif[11];

int main(){
    for(i=1;i<=10;i++){
        scanf("%d", &N);
        for(j=0;j<100;j++){
            scanf("%d", &num[j]);
        }
        while(N-->0){     
            sort(num, num+100);
            num[0]++;
            num[99]--;
        }
        sort(num, num+100);
        dif[i] = num[99] - num[0];
    }
    for(i=1;i<=10;i++){
        printf("#%d %d\n", i, dif[i]);
    }
    return 0;
}