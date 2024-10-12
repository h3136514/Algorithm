#include<iostream>
#include<queue>
#include<vector>

#define INF 10000000001
using namespace std;
int N, M, u, v, c, s, e;
long long dp[1001];
vector<pair<int,int>> V[1001];
priority_queue<pair<int,int>> q;

void dijkstra(int start){
    dp[start] = 0;
    q.push({0, start});

    while(!q.empty()){
        int currentV = q.top().second;
        int currentCost = -q.top().first;
        q.pop();

        if(dp[currentV] < currentCost)
            continue;
        
        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i].first;
            int cost = V[currentV][i].second + currentCost;

            if(dp[iv] > cost){
                dp[iv] = cost;
                q.push({-cost, iv});
            }
        }
    }
}

// 최소비용 구하기
int main(){
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> c;
        V[u].push_back({v, c});
    }
    cin >> s >> e;

    for(int i = 1; i <= N; i++){
        dp[i] = INF;
    }

    dijkstra(s);

    cout << dp[e] << "\n";

    return 0;
}
