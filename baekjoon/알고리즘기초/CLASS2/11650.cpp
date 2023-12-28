#include<cstdio>
#include<queue>
using namespace std;
priority_queue <pair<int,int>> q;
int N, X, Y, i;
int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d %d", &X, &Y);
        q.push({-X, -Y});
    }

    for(i=0;i<N;i++){
        X = -q.top().first;
        Y = -q.top().second;
        q.pop();
        printf("%d %d\n", X, Y);
    }

    return 0;
}