#include<cstdio>
#include<queue>
using namespace std;
int N, x, y, i;
priority_queue <pair<int, int>>q;

int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d",&x, &y);
        q.push({-y,-x});
    }
    for(i=0;i<N;i++){
        printf("%d %d\n",-q.top().second, -q.top().first);
        q.pop();
    }
    return 0;
}