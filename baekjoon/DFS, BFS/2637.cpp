#include <iostream>
#include <vector>
#include <map>

using namespace std;
int N, M, X, Y, K;
vector<pair<int, int>> V[101];
map<int, long long> result[101];  // result[i] = i번 부품을 만드는데 필요한 기본 부품들
bool visited[101];

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = true;
    
    // 기본 부품인 경우
    if (V[node].size() == 0) {
        result[node][node] = 1;
        return;
    }
    
    // 중간 부품인 경우
    for (int i = 0; i < V[node].size(); i++) {
        int nextNode = V[node][i].first;
        int cnt = V[node][i].second;
        
        // 하위 부품 먼저 계산
        dfs(nextNode);
        
        // 하위 부품의 기본 부품들을 현재 부품에 추가
        for (auto& p : result[nextNode]) {
            result[node][p.first] += p.second * cnt;
        }
    }
}

// 장난감 조립
int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> X >> Y >> K;
        V[X].push_back({ Y, K });
    }
    
    dfs(N);
    
    for (auto p : result[N]) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}