// dfs
#include <iostream>
#include <queue>

using namespace std;
int N, M, R, a, b, cnt = 1, visitied[100001];
priority_queue<int> q[100001];

void dfs(int start){
    visitied[start] = cnt++;

    while(!q[start].empty()){
        int iv = -q[start].top();
        q[start].pop();

        if(!visitied[iv]){
            dfs(iv);
        }
    }
}

// 알고리즘 수업 - 깊이 우선 탐색 1
int main(){
    cin >> N >> M >> R;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        q[a].push(-b);
        q[b].push(-a);
    }

    dfs(R);

    for(int i = 1; i <= N; i++){
        cout << visitied[i] << "\n";
    }

    return 0;
}

