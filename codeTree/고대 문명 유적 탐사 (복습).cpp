#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int K, M, num, board[5][5], tmpBoard[5][5], copyedBoard[5][5], visitied[5][5], CNT;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
queue<int> gold;
priority_queue<pair<pair<int, int>, pair<int, int>>> choosedBoardQ;
vector<pair<int, int>> path;

// 범위 확인
bool check(int x, int y) {
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}

// 초기화
void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visitied[i][j] = 0;
		}
	}
	path.clear();
}

//출력
void pri() {
	cout << "------------------\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------\n";
}

void copyBoard() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			copyedBoard[i][j] = board[i][j];
		}
	}
}

void pasteBoard() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			board[i][j] = copyedBoard[i][j];
		}
	}
}


void copyTmpBoard() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmpBoard[i][j] = board[i][j];
		}
	}
}

void pasteTmpBoard() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			board[i][j]= tmpBoard[i][j];
		}
	}
}


void rotate90(int startX, int startY, int endX, int endY) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[startY + j][startX+ 3 - i -1] = copyedBoard[startY +i][startX + j];
		}
	}
}

int searchBfs(int x, int y, bool save) {
	int cnt = 1;
	q.push({x, y});
	visitied[y][x] = 1;
	if (save)
		path.push_back({ x, y });

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int ix = currentX + offer_X[i];
			int iy = currentY + offer_Y[i];

			if (check(ix, iy) && !visitied[iy][ix] && board[currentY][currentX] == board[iy][ix]) {
				visitied[iy][ix] = 1;
				cnt++;
				if (save)
					path.push_back({ ix, iy });
				q.push({ ix, iy});
			}
		}
	}

	return cnt;
}

// 겪자 선택
bool chooseBoard() {
	int startX = 0, startY = 0, endX = 2, endY = 2;
	
	while (endY < 5) {
		copyTmpBoard();

		// 90도(3), 180도(2), 270도(1) 시계방향회전
		for (int i = 3; i > 0; i--) {
			copyBoard();
			rotate90(startX, startY, endX, endY);
			
			int sum = 0;
			for (int l = 0; l < 5; l++) {
				for (int j = 0; j < 5; j++) {
					if (!visitied[l][j]) {
						int cnt = searchBfs(j, l, false);
				
						if (cnt >= 3)
							sum += cnt;
					}
				}
			}
			if (sum >= 3)
				choosedBoardQ.push({ {sum, i}, {-(startX + 1), -(startY + 1)} });

			init();
		}

		if (endX == 4) {
			startX = 0;
			startY++;
			endX = 2;
			endY++;
		}
		else {
			startX++;
			endX++;
		}

		pasteTmpBoard();
	}

	if (choosedBoardQ.empty())
		return false;

	int sum = choosedBoardQ.top().first.first;
	int d = choosedBoardQ.top().first.second;
	int x = - choosedBoardQ.top().second.first;
	int y = - choosedBoardQ.top().second.second;

	while (!choosedBoardQ.empty())
		choosedBoardQ.pop();

	// 선택한 격자 실행
	for (int i = d; i <= 3; i++) {
		copyBoard();
		rotate90(x-1, y-1, x+1, y+1);
	}
	
	return true;
}

// 유적 벽면 유물 추가
void wallAdd() {
	for (int i = 0; i < 5; i++) {
		for (int j = 4; j >= 0; j--) {
			if (board[j][i] == 0) {
				board[j][i] = gold.front();
				gold.pop();
			}
		}
	}
}

int main() {
	cin >> K >> M;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> num;
		gold.push(num);
	}

	while (K--) {
		// 탐사진행(만약 유물을 획득 못할시)
		if (!chooseBoard())
			break;
		
		// 유물 연쇄획득
		while (true) {
			int sum = 0;
			for (int l = 0; l < 5; l++) {
				for (int j = 0; j < 5; j++) {
					if (!visitied[l][j] && board[l][j]) {
						int cnt = searchBfs(j, l, true);
				
						if (cnt >= 3) {
							sum += cnt;
							for (int i = 0; i < path.size(); i++) {
								board[path[i].second][path[i].first] = 0;
							}
						}
						path.clear();
							
					}
				}
			}

			if (sum == 0)
				break;
			else
				CNT += sum;

			wallAdd();

			init();
		}

		if(CNT == 0)
			break;

		cout << CNT << " ";

		CNT = 0;
		init();
	}

	return 0;
}