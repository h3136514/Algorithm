#include<cstdio>
#include <queue>
using namespace std;
priority_queue <pair<int,int>> q;
priority_queue <int> N;
int sum, num, i;

int main(){
    for(i=1;i<=8;i++){
        scanf("%d", &num);
        q.push({num, i});
    }
    for(i=0;i<5;i++){
        sum += q.top().first;
        N.push(-q.top().second);
        q.pop();
    }
    printf("%d\n", sum);
    for(i=0;i<5;i++){
        printf("%d ", -N.top());
        N.pop();
    }
    return 0;
}