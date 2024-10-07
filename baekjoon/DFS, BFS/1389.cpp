// BFS
#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
int N, M, u, v, CNT = INF, result, visitied[101];
queue<pair<int, int>> q;
vector<int> V[101];

// 방문 초기화
void init() {
    for(int i = 1; i <= N; i++)
        visitied[i] = 0;
}

// bfs (출발점에서 모든 관계수 합)
int bfs(int start) {
    int cnt = 0;
    q.push({0, start});
    visitied[start] = 1;

    while(!q.empty()) {
        int currentV = q.front().second;
        int currentCNT = q.front().first;
        q.pop();

        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];

            if(!visitied[iv]){
                visitied[iv] = 1;
                cnt += currentCNT + 1;  // 해당 사람까지 오는데 걸린 관계수를 더함
                q.push({currentCNT + 1, iv});
            }
        }

    }

    return cnt;
}

// 케빈 베이컨의 6단계 법칙
int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    for(int i = 1; i <= N; i++) {
        int cnt = bfs(i);
        if(CNT > cnt) {
            CNT = cnt;
            result = i;
        }

        init();
    }

    cout << result << "\n";

    return 0;
}