#include <iostream>
#include <queue>

#define INF 987654321
using namespace std;
int N, E, a, b, c, v1, v2, dp[801];
int result1;    // 1 => v1 => v2 => N
int result2;    // 1 => v2 => v1 => N
vector<pair<int, int>> V[801];
priority_queue<pair<int, int>> q;
bool check1, check2;

void init(){
    for(int i = 1; i <= N; i++)
        dp[i] = INF;
}

void dijkstra(int start) {
    q.push({0, start});
    dp[start] = 0;

    while(!q.empty()){
        int currentV = q.top().second;
        int currentCost = -q.top().first;
        q.pop();
        
        if(dp[currentV] < currentCost)
            continue;
        
        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i].first;
            int icost = V[currentV][i].second + currentCost;
            
            if(dp[iv] > icost){
                dp[iv] = icost;
                q.push({-icost, iv});
            }

        }
    }
}

// 특정한 최단 경로
int main(){
    cin >> N >> E;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        V[a].push_back({b, c});
        V[b].push_back({a, c});
    }
    cin >> v1 >> v2;
     
    init();
    dijkstra(1);
    // 1 => v1;
    if(dp[v1] == INF)
        check1 = true;
    else
        result1 += dp[v1];
    // 1 => v2;
    if(dp[v2] == INF)
        check2 = true;
    else
        result2 += dp[v2];


    init();
    dijkstra(v1);
    // v1 => v2
    if(dp[v2] == INF)
        check1 = true;
    else
        result1 += dp[v2];
    // v1 => N
    if(dp[N] == INF)
        check2 = true;
    else
        result2 += dp[N];

    init();
    dijkstra(v2);
    // v2 => N
    if(dp[N] == INF)
        check1 = true;
    else
        result1 += dp[N];
    // v2 => v1
    if(dp[v1] == INF)
        check2 = true;
    else
        result2 += dp[v1];


    // 출력
    if(check1 && check2)
        cout << "-1\n";
    else if(check1)
        cout << result2 << "\n";
    else if(check2)
        cout << result1 << "\n";
    else
        cout << min(result1, result2) << "\n";

    return 0;
}