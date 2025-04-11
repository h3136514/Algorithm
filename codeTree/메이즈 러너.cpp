#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, K, pX, pY, exitX, exitY, distSum, CNT, board[11][11], copyedBoard[11][11];
int player[11][11], copyedPlayer[11][11];
int offer_X[4] = { 1, -1, 0, 0 };
int offer_Y[4] = { 0, 0, 1, -1 };
priority_queue<pair<int, int>> distQ;

// 범위 확인
bool check(int x, int y) {
	return x > 0 && x <= N && y > 0 && y <= N;
}

// 거리 계산
int accurateDist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

// 임시저장소 반영(참가자)
void pastePlayer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == exitY && j == exitX) { 
				CNT += copyedPlayer[i][j];
				copyedPlayer[i][j] = 0;
				player[i][j] = 0;
		
				continue;
			}

			player[i][j] = copyedPlayer[i][j];
			copyedPlayer[i][j] = 0;
		}
	}

}

// 참가자들 이동(임시저장소)
void movePlayer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (player[i][j]) {
				int currentDist = accurateDist(j, i, exitX, exitY);

				for (int l= 0; l < 4; l++) {
					int ix = j + offer_X[l];
					int iy = i + offer_Y[l];
					int idist = accurateDist(ix, iy, exitX, exitY);
					
					if (check(ix, iy) && board[iy][ix] < 1) {
						distQ.push({ -idist, l });
					}

				}

				if (distQ.empty()) {
					copyedPlayer[i][j] += player[i][j];
				}else{
					int idist = -distQ.top().first;
					int d = distQ.top().second;
					
					if (currentDist > idist) { // 이동
						int ix = j + offer_X[d];
						int iy = i + offer_Y[d];

						copyedPlayer[iy][ix] += player[i][j];
						distSum += player[i][j];
					}
					else { // 이동X
						copyedPlayer[i][j] += player[i][j];
					}
				}

				while (!distQ.empty())
					distQ.pop();
			}

		}
	}

	pastePlayer();
}

// 격자 가능유무 판별
bool findBroad(int startX, int startY, int endX, int endY) {
	bool checkExit = ((startX <= exitX) && (endX >= exitX) && (startY <= exitY) && (endY >= exitY)) ? true : false;
	bool checkPlayer = false;
	for (int i = startY; i <= endY; i++) {
		for (int j = startX; j <= endX; j++) {
			if(player[i][j])
				checkPlayer = true;
		}
	}
	//cout << "탈출구: " << exitX << "," << exitY << "\n";
	//cout << "좌표 유무: " << startX << "," << startY << " ~ " << endX << "," << endY << ".... " << checkExit  << " " << checkPlayer << "\n";
	return (checkExit && checkPlayer);
}

// 복사본 적용
void pasteTotall(int startX, int startY, int endX, int endY) {
	for (int i = startY; i <= endY; i++) {
		for (int j = startX; j <= endX; j++) {
			board[i][j] = copyedBoard[i][j];
			player[i][j] = copyedPlayer[i][j];

			if (copyedBoard[i][j] < 0) {	// 탈출구 옮기기
				exitY = i;
				exitX = j;
			}

			copyedBoard[i][j] = 0;
			copyedPlayer[i][j] = 0;
		}
	}
}

// 범위 회전
void rotate90(int startX, int startY, int endX, int endY, int n) {

	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			if (board[startY + i][startX + j])
				copyedBoard[startY + j][startX  + n - i  - 1] = board[startY + i][startX + j] - 1;  // 내구도 감소
			else
				copyedBoard[startY + j][startX + n - i - 1] = board[startY + i][startX + j];

			copyedPlayer[startY + j][startX + n - i - 1] = player[startY + i][startX + j];

		}
	}

	// 복사본 적용
	pasteTotall(startX, startY, endX, endY);


}


// 미로 회전
void miro() {
	bool find = false;
	int startX, startY, endX, endY, idx;
	for (idx = 1; idx < 10; idx++) {
		startX = 1, startY = 1, endX = startX + idx, endY = startY + idx;

		while (endY <= N) {
			if (findBroad(startX, startY, endX, endY)) {
				find = true;
				break;
			}
			
			if (endX == N) {
				startX = 1;
				startY++;
				endX = startX + idx;
				endY++;
			}
			else {
				startX++;
				endX++;
			}

		}

		if (find)
			break;
	}

	// 격자 회전
	rotate90(startX, startY, endX, endY, idx+1);
	//cout << "회전: " << startX << "," << startY << " ~ " << endX << "," << endY << ".... " << idx + 1 << "\n";
	

}

void pri() {
	cout << "\n";
	cout << "board-------------------------\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "player-------------------------\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << player[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> pY >> pX;
		player[pY][pX]++;
	}
	cin >> exitY >> exitX;
	board[exitY][exitX] = -1;

	int C = K;
	while (K--) {
		//cout << C-K << "\n";
		movePlayer();
		//pri();

		if (M <= CNT)	//모든 참가자가 탈출에 성공한 경우
			break;

		miro();
		//pri();
	}

	cout << distSum << "\n";
	cout << exitY << " " << exitX << "\n";

	return 0;
}