// BFS
#include <iostream>
#include <queue>
#include <unordered_map>

#define INF 987654321
using namespace std;
int N, M, u, v, CNT, num[6], dp[101];
unordered_map<int, int> cline, snake;
queue<pair<int, int>> q;

// 범위 확인
bool check(int x) {
	return 1 <= x && x <= 100;
}

void bfs() {
	dp[1] = 1;
	q.push({ 0, 1 });

	while (!q.empty()) {
		int currentCNT = q.front().first;
		int currentX = q.front().second;
		q.pop();

		if (currentX == 100) {
			CNT = currentCNT;
			return;
		}

		if (dp[currentX] < currentCNT)
			continue;
		
		for (int i = 0; i < 6; i++) {
			num[i] = currentX + i + 1;
			if (!check(num[i]))
				break;

			if (cline.find(num[i]) != cline.end()) {
				num[i] = cline[num[i]];
			}
			else if (snake.find(num[i]) != snake.end()) {
				num[i] = snake[num[i]];
			}

			if (check(num[i]) && dp[num[i]] >= currentCNT + 1) {
				dp[num[i]] = currentCNT + 1;
				q.push({ currentCNT + 1 ,num[i]});
			}

		}
		
	}
}

// 뱀과 사다리 게임
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> u >> v;
		cline[u] = v;
	}
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		snake[u] = v;
	}

	// 값 초기화
	for (int i = 1; i <= 100; i++)
		dp[i] = INF;

	bfs();

	cout << CNT << "\n";

	return 0;
}