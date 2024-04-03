#include<cstdio>
#include<queue>
using namespace std;
priority_queue <int> q[10001];
int i, N, M, A, B, cnt, num[10001];//방문표시

void dfs(int start) {
    if(num[start])
        return;
    num[start] = 1;
    while(!q[start].empty()) {
        int x =q[start].top();
        q[start].pop();
        dfs(x);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(i=0;i<M;i++) {
        scanf("%d %d", &A, &B);
        q[A].push(B);
        q[B].push(A);
    }
    for(i=1;i<=N;i++) {
        if(num[i])
            continue;
        cnt++;
        dfs(i);
    }

    printf("%d\n", cnt);

    return 0;
}