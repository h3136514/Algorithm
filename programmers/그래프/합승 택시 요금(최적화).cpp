// https://school.programmers.co.kr/learn/courses/30/lessons/72413?language=cpp
#include <string>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
int N;
long long dp[3][201]; // dp[0] = s 기준, dp[1] = a 기준, dp[2] = b 기준
vector<pair<int, int>> V[201];

void init(int idx){
    for(int i = 1; i <= N; i++){
        dp[idx][i] = INF;
    }
}

void dijkstra(int idx, int start){
    priority_queue<pair<int, int>> q;
    q.push({0, start});
    dp[idx][start] = 0;

    while(!q.empty()){
        int currentCost = -q.top().first;
        int currentV = q.top().second;
        q.pop();

        if(dp[idx][currentV] < currentCost)
            continue;

        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i].first;
            int icost = currentCost + V[currentV][i].second;

            if(dp[idx][iv] > icost){
                dp[idx][iv] = icost;
                q.push({-icost, iv});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = 0;
    N = n;
    for(int i = 0; i < fares.size(); i++){
        int v1 = fares[i][0];
        int v2 = fares[i][1];
        int c = fares[i][2];

        V[v1].push_back({v2, c});
        V[v2].push_back({v1, c});
    }

    // s, a, b 세 지점에서 각각 딱 한 번씩만 다익스트라 실행
    init(0);
    dijkstra(0, s);

    init(1);
    dijkstra(1, a);

    init(2);
    dijkstra(2, b);

    // 모든 지점 i를 합승 분기점 후보로 놓고,
    // s->i + i->a + i->b 가 최소가 되는 지점을 탐색
    answer = INF;
    for(int i = 1; i <= n; i++){
        answer = min(answer, dp[0][i] + dp[1][i] + dp[2][i]);
    }

    return answer;
}