// https://www.acmicpc.net/problem/1939
#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000001
using namespace std;
int N, M, A, B, C, r1, r2, CNT, dp[10001];
vector<pair<int, int>> V[10001];
priority_queue<pair<int, int>> q;

void disktra() {
    q.push({ INF, r1 });
    dp[r1] = INF;

    while (!q.empty()) {
        int currentV = q.top().second;
        int currentCost = q.top().first;
        q.pop();

        if (dp[currentV] > currentCost) // 최대 중량이 기존께 더 크면 무시
            continue;

        for (int i = 0; i < V[currentV].size(); i++) {
            int iv = V[currentV][i].first;
            int icost = min(currentCost, V[currentV][i].second);    // 더 작은 최대 중량 적용
            if (dp[iv] < icost) {
                dp[iv] = icost;

                q.push({ icost, iv });
            }
        }
    }

}

// 중량제한
int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dp[i] = -1;

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;

        V[A].push_back({ B, C });
        V[B].push_back({ A, C });
    }
    cin >> r1 >> r2;

    disktra();

    cout << dp[r2] << "\n";

    return 0;
}