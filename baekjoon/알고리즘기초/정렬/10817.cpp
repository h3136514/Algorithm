#include<cstdio>
#include<algorithm>
using namespace std;
int num[3], i;

int main(){
    for(i=0; i<3; i++){
        scanf("%d", &num[i]);
    }
    sort(num, num+3);
    printf("%d\n",num[1]);
    return 0;
}