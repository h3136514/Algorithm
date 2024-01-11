#include<cstdio>
#include<queue>
using namespace std;
int N, i, num, cnt, sum;
priority_queue <int> q;

int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d", &num);
        q.push(-num);
    }
    for(i=0;i<N;i++){
        num=-q.top();
        cnt +=num;
        sum +=cnt;
        q.pop();
    }
    printf("%d\n", sum);
}