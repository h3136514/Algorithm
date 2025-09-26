#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define INF 987654321
using namespace std;
int N, Q, R1, C1, R2, C2, dp[51][51][6], result;
int offer_X[4] = { 1, 0, -1, 0 };
int offer_Y[4] = { 0, 1, 0, -1 };
char board[51][51];
priority_queue<pair<pair<int, int>, pair<int, int>>> q;

bool check(int x, int y) {
	return x > 0 && x <= N && y > 0 && y <= N;
}


void init() {
	result = INF;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= 5; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
}

// 점프 확인
bool checkJump(int x, int y, int k, int d) {
	for (int i = 0; i < k; i++) {
		x += offer_X[d];
		y += offer_Y[d];

		if (!check(x, y))
			return false;

		if (board[y][x] == '#')
			return false;
	}

	if (board[y][x] == 'S')
		return false;

	return true;
}


void dijsktra() {
	dp[R1][C1][1] = 0;
	q.push({ {0, 1}, {C1, R1} });

	while (!q.empty()) {
		int currentT = -q.top().first.first;
		int currentK = q.top().first.second;
		int currentX = q.top().second.first;
		int currentY = q.top().second.second;
		q.pop();
		//cout << currentY << ", " << currentX << "\n";

		if (dp[currentY][currentX][currentK] < currentT)
			continue;

		if (C2 == currentX && R2 == currentY) {
			result = min(result, currentT);
		}

		// 점프
		for (int i = 0; i < 4; i++) {
			int ix = currentX + (offer_X[i] * currentK);
			int iy = currentY + (offer_Y[i] * currentK);
			int it = currentT + 1;

			if (check(ix, iy) && checkJump(currentX, currentY, currentK, i) && dp[iy][ix][currentK] > it) {
				dp[iy][ix][currentK] = it;
				q.push({ {-it, currentK}, {ix, iy} });
			}
		}

		// 점프력 증가
		if (currentK != 5) {
			int ik = currentK + 1;
			int it = currentT + (ik * ik);

			if (dp[currentY][currentX][ik] > it) {
				dp[currentY][currentX][ik] = it;
				q.push({ {-it, ik}, {currentX, currentY} });
			}
		}

		// 점프력 감소
		if (currentK != 1) {
			int it = currentT + 1;
			for (int i = currentK - 1; i >= 1; i--) {

				if (dp[currentY][currentX][i] > it) {
					dp[currentY][currentX][i] = it;

					q.push({ {-it, i}, {currentX, currentY} });
				}
			}
		}
	}

}

void priJump() {
	cout << "--------------\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= 5; k++) {
				if (dp[i][j][k] == INF)
					dp[i][j][k] = 0;

				cout << dp[i][j][k] <<",";
			}
			cout << " ";
		}
		cout << "\n";
	}
	cout << "--------------\n";
}


int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		init();
		cin >> R1 >> C1 >> R2 >> C2;

		dijsktra();

		if (result == INF)
			result = -1;

		cout << result << "\n";
	}


	return 0;
}