#include<cstdio>
#include <algorithm>
using namespace std;
int num[3], i;

int main(){
    for(i=0;i<3;i++)
        scanf("%d", &num[i]);
    sort(num, num+3);
    if(num[2] < num[0] + num[1])
        printf("%d\n", num[0] + num[1]+num[2]);
    else
        printf("%d\n",(num[0] + num[1]) * 2 - 1);

    return 0;
}