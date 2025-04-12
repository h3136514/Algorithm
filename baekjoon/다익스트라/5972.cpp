#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;
int N, M, C, ai, bi, ci, dp[50001];
priority_queue<pair<int, int>> q;
vector<pair<int, int>> V[50001];

void init() {
	for (int i = 1; i <= N; i++)
		dp[i] = INF;
}

void dijkstra() {
	dp[1] = 0;
	q.push({ 0, 1 });

	while (!q.empty()) {
		int currentV = q.top().second;
		int currentCost = -q.top().first;
		q.pop();

		if (dp[currentV] < currentCost)
			continue;

		for (int i = 0; i < V[currentV].size(); i++) {
			int iv = V[currentV][i].first;
			int icost = currentCost + V[currentV][i].second;

			if (dp[iv] > icost) {
				dp[iv] = icost;
				q.push({ -icost, iv });
			}
		}
	}
}

// 택배 배송
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> ai >> bi >> ci;
		V[ai].push_back({ bi, ci });
		V[bi].push_back({ ai, ci });
	}

	init();

	dijkstra();

	cout << dp[N] << "\n";

}