#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int K, V, E, u, v, check, visitied[20001];  // 0 : 방문안함, 1, 2 : 인접 구분
vector<int> ver[20001];
queue<int> q;

// 초기화
void init() {
    check = 0;
    for(int i = 1; i <= V; i++) {
        visitied[i] = 0;
        ver[i].clear();
    }

    while(!q.empty())
        q.pop();
}

// bfs
bool bfs(int start) {
    q.push(start);
    visitied[start] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i = 0; i < ver[x].size(); i++) {
            int ix = ver[x][i];
    
            if(visitied[ix] == visitied[x]){ // 인접 발생
                return false;
            }
            if(!visitied[ix]) {
                visitied[ix] = (visitied[x] == 1) ? 2 : 1;  // 인접 구분
                q.push(ix);
            }
        }
    }

    return true;
}

// 이분 그래프
int main() {
    cin >> K;
    while(0 < K--) {
        cin >> V >> E;
        init();
        for(int i = 0; i < E; i++) {
            cin >> u >> v;
            ver[u].push_back(v);
            ver[v].push_back(u);
        }

        bool isYes = false;
        for(int i = 1; i <= V; i++){    // 여러 그래프가 있을 수 있으므로(모든 정점 확인)
            if(!visitied[i]) {
                isYes = bfs(i);
            }
            if(!isYes)  // 하나라도 인접해 있으면 X
                check = 1;
        }

        if(!check)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

    }

    return 0;
}