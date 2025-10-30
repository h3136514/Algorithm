#include <iostream>
#include <queue>

using namespace std;
int R, C, N, T, timer[201][201];
int offer_X[4] = { 1, 0, -1, 0 };
int offer_Y[4] = { 0, 1, 0, -1 };
char board[201][201];
queue < pair<int, int>> q;

bool check(int x, int y) {
	return x >= 0 && x < C && y >= 0 && y < R;
}

void checkTimer(int t) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (timer[i][j] == t) {
				q.push({ j, i });

				timer[i][j] = 0;
				for (int k = 0; k < 4; k++) {
					int ix = j + offer_X[k];
					int iy = i + offer_Y[k];

					if (check(ix, iy) && timer[iy][ix] > 0)
						q.push({ ix, iy});
				}
			}
		}
	}

	while (!q.empty()) {
		int ix = q.front().first;
		int iy = q.front().second;
		q.pop();

		timer[iy][ix] = 0;
	}
}

void makeBomb(int t) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (timer[i][j] == 0) {
				timer[i][j] = t + 3;
			}
		}
	}
}

// 출력
void pri() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (timer[i][j] > 0)
				cout << "O";
			else
				cout << ".";
		}
		cout << "\n";
	}
}

// 봄버맨
int main() {
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'O') {
				timer[i][j] = 3;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (i != 1 && i % 2 == 1) {
			checkTimer(i);
			continue;
		}

		if (i % 2 == 0) {
			makeBomb(i);
		}
	}

	pri();

	return 0;
}