// 다익스트라
#include <iostream>
#include <queue>
#include <vector>

#define INF 3000000
using namespace std;
int V, E, K, u, v, w, dp[20001];
vector<pair<int, int>> ver[20001];
priority_queue<pair<int, int>> q;

void init() {
    for(int i = 1; i <= V; i++) {
        dp[i] = INF;
    }
}

void dijkstra(){
    q.push({0, K});
    dp[K] = 0;

    while(!q.empty()) {
        int currentV = q.top().second;
        int currentCost = - q.top().first;
        q.pop();

        if(dp[currentV] < currentCost)
            continue;

        for(int i = 0; i < ver[currentV].size(); i++) {
            int iv = ver[currentV][i].first;
            int icost = ver[currentV][i].second + currentCost;

            if(dp[iv] > icost) {
                dp[iv] = icost;
                q.push({-icost, iv});
            }
        }

    }

}

// 최단경로(백준 1753번)
int main() {
    cin >> V >> E;
    cin >> K;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        ver[u].push_back({v, w}); 
    }

    init();
    dijkstra();

    for(int i = 1; i <= V; i++){
        if(dp[i] == INF)
            cout << "INF" << "\n";
        else
            cout << dp[i] << "\n";
    }

    return 0;
}
