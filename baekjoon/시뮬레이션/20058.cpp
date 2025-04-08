#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
int N, Q, L, Nsize, A[65][65], cooyA[65][65], visitied[65][65], sumA, maxIce;
int offer_X[4] = { 1, 0, -1, 0 };
int offer_Y[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
vector<pair<int, int>> decreaseIce;

// 범위 확인
bool check(int x, int y) {
	return x > 0 && x <= Nsize && y > 0 && y <= Nsize;
}

// 배열 복사
void pastBoared(int x1, int y1, int x2, int y2) {
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			A[i][j] = cooyA[i][j];
		}
	}
}

// 회전
void rotate90(int n, int x1, int y1, int x2, int y2) {

	 // 시계방향 90도 회전
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cooyA[y1 + j][x1 + n-i-1] = A[y1 + i][x1 + j];
		}
	}
	
	pastBoared(x1, y1, x2, y2);
}

// 얼음 녹이기
void decrease() {
	for (int i = 1; i <= Nsize; i++) {
		for (int j = 1; j <= Nsize; j++) {
			if (A[i][j] == 0)
				continue;

			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ix = j + offer_X[k];
				int iy = i + offer_Y[k];

				if (check(ix, iy) && A[iy][ix]) {
					cnt++;
				}
			}
			if (cnt < 3) {
				decreaseIce.push_back({ j, i });
			}
		}
	}

	for (int i = 0; i < decreaseIce.size(); i++) {
		A[decreaseIce[i].second][decreaseIce[i].first]--;
	}

	decreaseIce.clear();
}

// 얼음 총합
void sum() {
	for (int i = 1; i <= Nsize; i++) {
		for (int j = 1; j <= Nsize; j++) {
			sumA += A[i][j];
		}
	}
}

// 가장큰 덩어리차지 칸
void bfs(int startX, int startY) {
	int cnt = 1;
	visitied[startY][startX] = 1;
	q.push({ startX , startY });

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ix = currentX + offer_X[k];
			int iy = currentY + offer_Y[k];

			if (check(ix, iy) && !visitied[iy][ix] && A[iy][ix]) {
				visitied[iy][ix] = 1;
				cnt++;
				q.push({ ix, iy });
			}
		}
	}

	maxIce = max(maxIce, cnt);
}


void pri() {
	cout << "------------\n";
	for (int i = 1; i <= Nsize; i++) {
		for (int j = 1; j <= Nsize; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------\n";
}

// 마법사 상어와 파이어스톰
int main() {
	cin >> N >> Q;
	Nsize = pow(2, N);
	for (int i = 1; i <= Nsize; i++) {
		for (int j = 1; j <= Nsize; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < Q; i++) {
		cin >> L;

		int n = pow(2, L);
		for (int j = 1; j < Nsize; j += n) {
			for (int k = 1; k < Nsize; k += n) {
				// 격자 크기 만큼 회전 
				rotate90(n, k, j, k+n-1, j+n-1);
			}
		}
		
		decrease();
	}

	sum();

	for (int i = 1; i <= Nsize; i++) {
		for (int j = 1; j <= Nsize; j++) {
			if (A[i][j] && !visitied[i][j]) {
				bfs(j, i);
			}
		}
	}

	cout << sumA << "\n";
	cout << maxIce << "\n";

	return 0;
}