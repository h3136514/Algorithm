#include <iostream>
#include <vector>

using namespace std;
int N, u, v, w, maxLen, node, visitied[10001];
vector<pair<int, int>> V[10001];

// 방문, 길이 초기화
void init(){
    maxLen = 0;
    for(int i = 1; i <= N; i++)
        visitied[i] = 0;
}

void dfs(int x, int dist){
    // 가장 먼 노드를 찾는다.
    if(dist > maxLen){
        maxLen = dist;
        node = x;
    }

    for(int i = 0; i < V[x].size(); i++){
        int ix = V[x][i].first;
        int idist = V[x][i].second;
        
        if(!visitied[ix]){
            visitied[ix] = 1;
            dfs(ix, dist + idist);
            visitied[ix] = 0;
        }
    }
}

// 트리의 지름 
int main() {
	cin >> N;

	for (int i = 0; i < N-1; i++) {
		cin >> u >> v >> w;
		V[u].push_back({v, w});
        V[v].push_back({u, w});
	}

    visitied[1] = 1;
    dfs(1, 0);  // 출발점에서 가장 먼노드를 찾는다.
    
    init();
    visitied[node] = 1;
    dfs(node, 0);   // 가장 먼노드에서 가장 먼 길이를 찾는다.

	cout << maxLen << "\n";
	
	return 0;
}