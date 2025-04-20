#include <string>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
int N;
long long dp[201], sum[201];
vector<pair<int, int>> V[201];
priority_queue<pair<int, int>> q;

void init(){
    for(int i = 1; i <= N; i++){
        dp[i] = INF;
    }
}

void dijkstra(int start){
    q.push({0, start});
    dp[start] = 0;
    
    while(!q.empty()){
        int currentCost = -q.top().first;
        int currentV = q.top().second;
        q.pop();
        
        if(dp[currentV] < currentCost)
            continue;
        
        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i].first;
            int icost = currentCost + V[currentV][i].second;
            
            if(dp[iv] > icost){
                dp[iv] = icost;
                q.push({-icost, iv});
            }
        }
        
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    N = n;
    for(int i = 0; i < fares.size(); i++){
        int v1 = fares[i][0];
        int v2 = fares[i][1];
        int c = fares[i][2];
        
        V[v1].push_back({v2, c});
        V[v2].push_back({v1, c});
    }
    
    init();
    dijkstra(s);
    
    answer = dp[a] + dp[b]; // 처음부터 각자 가는거(시작점 -> a + 시작점 -> b)
    // 시작점 -> i지점
    for(int i = 1; i <= n; i++)
        sum[i] = dp[i];
    
    // i지점 -> a지점 + i지점 -> b지점 (i까지는 같이 가고 각자 집에 가는 경우)
     for(int i = 1; i <= n; i++){
         if(i == s)
            continue;
         
         init();
         dijkstra(i);
         
         answer = min((long long)answer, sum[i] + dp[a] + dp[b]);
     }
    
    return answer;
}