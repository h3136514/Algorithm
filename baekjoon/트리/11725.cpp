// DFS
#include <iostream>
#include <vector>

using namespace std;
int N, a, b, visited[100001], parent[100001];
vector<int> V[100001];

// dfs
void dfs(int x) {
    if(visited[x])
        return;
    
    visited[x] = 1;
    for(int i = 0; i < V[x].size(); i++) {
        int ix = V[x][i];
        if(!visited[ix]) {
            parent[ix] = x; // 부모 설정
            dfs(ix);
        }
    }
}

// 트리의 부모 찾기 
int main() {
    cin >> N;
   
    for(int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    
    dfs(1); // 출발점에서 탐색 시작

    for(int i = 2; i <= N; i++)
        cout << parent[i] << "\n";

    return 0;
}