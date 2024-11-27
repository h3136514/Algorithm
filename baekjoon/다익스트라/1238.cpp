#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
int N, M, X, u, v, w, maxTime, dp[1001];
vector<pair<int, int>> V[1001];
priority_queue<pair<int, int>> q;

void init() {
	for (int i = 1; i <= N; i++)
		dp[i] = INF;
}

void dijkstra(int start) {
	q.push({ 0, start });
	dp[start] = 0;

	while (!q.empty()) {
		int currentV = q.top().second;
		int currentW = -q.top().first;
		q.pop();

		if (dp[currentV] < currentW)
			continue;

		for(int i = 0; i < V[currentV].size(); i++) {
			int iv = V[currentV][i].first;
			int iw = V[currentV][i].second + currentW;

			if (dp[iv] > iw) {
				dp[iv] = iw;
				q.push({ -iw, iv });
			}
		}
	}

}

// 파티
int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		V[u].push_back({v, w});
	}

	for (int i = 1; i <= N; i++) {
		init();
		dijkstra(i);
		int sum = dp[X];	// i => X로 가능 최단시간

		init();
		dijkstra(X);
		sum += dp[i]; // X => i로 가능 최단시간

		maxTime = max(maxTime, sum);
	}

	cout << maxTime << "\n";
	
	return 0;
}
