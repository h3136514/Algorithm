#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321
using namespace std;
int R, C, K, W, D, X, Y, num, Chocolate, visitied[22][22], board[22][22], copyedBoard[22][22];
int offer_X[4] = { 1, -1, 0, 0 };
int offer_Y[4] = { 0, 0, -1, 1 };
vector<int> v[22][22];
vector<pair<int, pair<int, int>>> warnAir;
vector<pair<int, int>> target;
queue<pair<int, pair<int, int>>> q;
queue<pair<int, int>> nearQ;

// 좌표 체크
bool check(int x, int y) {
	return x > 0 && x <= C && y > 0 && y <= R;
}

// 좌표 체크 겉에면
bool checkOut(int x, int y) {
	return x >= 0 && x <= C+1 && y >= 0 && y <= R+1;
}

// 방문 초기화
void init() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			visitied[i][j] = 0;
		}
	}
}

// 출력
void pri() {
	cout << "--------------\n";
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "--------------\n";
}

// 온풍기 작동
void working(int startX, int startY, int d) {
	// 맨처음 한칸 이동(온풍기 방향)
	startX += offer_X[d];
	startY += offer_Y[d];
	visitied[startY][startX] = 1;
	q.push({ 5, {startX, startY} });

	while (!q.empty()) {
		int currentX = q.front().second.first;
		int currentY = q.front().second.second;
		int currentCNT = q.front().first;
		q.pop();

		if (currentCNT <= 0)
			continue;
		board[currentY][currentX] += currentCNT;

		// 정면 방향
		int ix1 = currentX + offer_X[d];
		int iy1 = currentY + offer_Y[d];
		if (check(ix1, iy1) && !visitied[iy1][ix1] && !v[currentY][currentX][d]) {
			visitied[iy1][ix1] = 1;
			q.push({ currentCNT - 1, {ix1, iy1} });
		}

		// 양쪽 방향
		int ix2 = ix1, ix3 = ix1, iy2 = iy1, iy3 = iy1;
		int id2, id3, id4;
		if (d < 2) {	//온풍기가 양옆에 작동할때(왼쪽 오른쪽)
			iy2 += offer_Y[2];	// 위
			iy3 += offer_Y[3];	// 아래
			id2 = 2, id3 = 3;	// 현재좌표에(온풍기가나오는) 위, 아래 방향 벽확인
			id4 = (d == 0) ? 1 : 0;	// 온풍기가 퍼질 좌표에 (온풍기가 나오는)반대표 방향(왼쪽, 오른쪽) 벽확인
		}
		else {// 온풍기가 위아래에 작동할때(위쪽 아래쪽)
			ix2 += offer_X[0];	// 오른쪽
			ix3 += offer_X[1];	// 왼쪽
			id2 = 0, id3 = 1;	// 현재좌표에(온풍기가나오는) 오른쪽, 왼쪽 방향 벽확인
			id4 = (d == 2) ? 3 : 2;	// 온풍기가 퍼질 좌표에 (온풍기가 나오는)반대표 방향(위, 아래쪽) 벽확인
		}

		if (check(ix2, iy2) && !visitied[iy2][ix2] && !v[currentY][currentX][id2] && !v[iy2][ix2][id4]) {
			visitied[iy2][ix2] = 1;
			q.push({ currentCNT - 1, {ix2, iy2} });
		}
		if (check(ix3, iy3) && !visitied[iy3][ix3] && !v[currentY][currentX][id3] && !v[iy3][ix3][id4]) {
			visitied[iy3][ix3] = 1;
			q.push({ currentCNT - 1, {ix3, iy3} });
		}

	}
}

void copyBoard() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			copyedBoard[i][j] = board[i][j];
		}
	}
}

void pasteBoard() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			board[i][j] = copyedBoard[i][j];
		}
	}
}

// 온도 조절
void temp() {
	copyBoard();

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			// 아랫방향(3), 오른쪽 방향(0) 비교(중복 비교 개선)
			for (int l = 0; l < 4; l+= 3) {
				if (v[i][j][l] == 1)	// 벽이 있으면 넘어감
					continue;
				int ix = j + offer_X[l];
				int iy = i + offer_Y[l];

				if (!check(ix,iy) || board[i][j] == board[iy][ix])	// 범위가 아니거나 온도가 같은 경우 넘어감
					continue;
				// 온도 퍼짐
				if (board[i][j] > board[iy][ix]) {
					int add = (board[i][j] - board[iy][ix]) / 4;
					copyedBoard[i][j] -= add;
					copyedBoard[iy][ix] += add;
				}
				else {
					int add = (board[iy][ix] - board[i][j]) / 4;
					copyedBoard[i][j] += add;
					copyedBoard[iy][ix] -= add;
				}
			}
		}
	}

	pasteBoard();
}

// 겉에 -1
void out() {
	// 아래
	for (int i = 1; i <= R; i++) {
		if (board[i][1] != 0)
			board[i][1]--;
	}

	// 오른쪽
	for (int i = 2; i <= C; i++) {
		if (board[R][i] != 0)
			board[R][i]--;
	}

	// 위
	for (int i = R-1; i >= 1; i--) {
		if (board[i][C] != 0)
			board[i][C]--;
	}
	
	// 왼쪽
	for (int i = C-1; i > 1; i--) {
		if (board[1][i] != 0)
			board[1][i]--;
	}

}

// 모든칸 조사
bool checkTarget() {
	for (int i = 0; i < target.size(); i++) {
		int ix = target[i].first;
		int iy = target[i].second;

		if (board[iy][ix] < K)
			return false;
	}

	return true;
}

// 온풍기 안녕!
int main() {
	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> num;
			if (num != 0) {
				if (num == 5) {	// 조사하는 칸
					target.push_back({ j, i });
				}
				else	// 온풍기 대입
					warnAir.push_back({ num - 1, {j, i} });
			}
		}
	}

	// 좌표별 벽 유무 설정
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			v[i][j].resize(4);
		}
	}

	cin >> W;
	for (int i = 0; i < W; i++) {
		cin >> Y >> X >> D;
		if (D == 0) {
			v[Y][X][2] = 1;	// 위 벽
			v[Y-1][X][3] = 1;	// 아래 벽(맞은편)
		}
		else {
			v[Y][X][0] = 1;	// 왼쪽 벽
			v[Y][X+1][1] = 1;	// 오른쪽 벽(맞은편)
		}
	}

	while (Chocolate < 101) {
		// 모든 온풍기 작동
		for (int i = 0; i < warnAir.size(); i++) {
			int directon = warnAir[i].first;
			int warnAirX = warnAir[i].second.first;
			int warnAirY = warnAir[i].second.second;

			// cout << warnAirY << ", " << warnAirX << ": " << directon << "\n";

			working(warnAirX, warnAirY, directon);

			init();
		}

		// 온도 조절
		temp();

		// 가장바깥쪽 -1
		out();
	
		// 초콜렛 증가
		Chocolate++;

		// 타겟 모든칸 조사
		if (checkTarget())
			break;

	}
	
	cout << Chocolate << "\n";

	return 0;
}