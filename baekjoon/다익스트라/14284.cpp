// https://www.acmicpc.net/problem/14284
#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
int n, m, a, b, c, s, t, dp[5001];
vector<pair<int, int>> v[5001];
priority_queue<pair<int, int>> q;

void dijsktra(){
    dp[s] = 0;
    q.push({0, s});

    while(!q.empty()){
        int currentV = q.top().second;
        int currentCnt = -q.top().first;
        q.pop();

        if(dp[currentV] < currentCnt)
            continue;
        
        for(int i = 0; i < v[currentV].size(); i++){
            int nextV = v[currentV][i].first;
            int nextCnt = v[currentV][i].second + currentCnt;

            if(dp[nextV] > nextCnt){
                dp[nextV] = nextCnt;
                q.push({-nextCnt, nextV});
            }
        }
    }
}

// 간선 이어가기 2
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        dp[i] = INF;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    cin >> s >> t;

    dijsktra();

    cout << dp[t] << "\n";

    return 0;
}
