#include <iostream>
#include <queue>

using namespace std;
int K, M, board[5][5], tmp[5][5], visitied[5][5], total;
int offer_X[4] = { 1, 0, -1, 0 };
int offer_Y[4] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;
queue<pair<int, int>> tmpq; // 임시(조각 위치 저장)
queue<int> mq;	// 조각들
priority_queue<pair<pair<int, int>, pair<int, int>>> boardsQ;	// 격자 선택 후보
priority_queue<pair<int, int>> fillq;	// 채울 조각 위치 순서

// 초기화
void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			visitied[i][j] = 0;
		}
	}
}
bool check(int x, int y) {
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}

// copy
void copyBoard() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp[i][j] = board[i][j];
		}
	}
}
//보존
void reserveBoard() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			board[i][j] = tmp[i][j];
		}
	}
 }

/*
void printBoard() {
	cout << "-------------------" << "\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}
*/

// 90도 회전
void rotate90(int x, int y) {
    for (int i = 0; i < 3; i++) {
		board[y - 1][x - 1 + i] = tmp[y + 1 - i][x - 1]; // 윗
		board[y - 1+i][x + 1] = tmp[y - 1][x - 1 + i]; // 오른쪽
		board[y + 1][x -1 + i] = tmp[y + 1 - i][x + 1]; // 밑
		board[y -1 + i][x - 1] = tmp[y + 1][x - 1 + i]; // 왼쪽
	}
    
}

// 180도 회전
void rotate180(int x, int y) {
	for (int i = 0; i < 3; i++) {
		board[y - 1][x - 1 + i] = tmp[y + 1][x + 1 - i]; // 윗
		board[y + 1][x + 1 - i] = tmp[y - 1][x - 1 + i]; // 밑
	}
    // 오른쪽 왼쪽
    board[y][x - 1] = tmp[y][x + 1];
    board[y][x + 1] = tmp[y][x - 1]; 
}

// 270도 회전
void rotate270(int x, int y) {
    board[y-1][x - 1] = tmp[y-1][x + 1];
    board[y-1][x] = tmp[y][x + 1];
    board[y-1][x + 1] = tmp[y+1][x + 1];
    board[y][x + 1] = tmp[y+1][x];
    board[y+1][x + 1] = tmp[y+1][x-1];
    board[y+1][x] = tmp[y][x-1];
    board[y+1][x-1] = tmp[y-1][x-1];
    board[y][x-1] = tmp[y-1][x];
}

// bfs(유물 조각 탐색)
int bfs(int x, int y, bool store) {
	q.push({ x, y });
	visitied[y][x] = 1;
	int c = 1;

	if (store) //
		tmpq.push({ -x, y });

	while (!q.empty()) {
		int currentX = q.front().first;
		int currentY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ix = currentX + offer_X[i];
			int iy = currentY + offer_Y[i];
			if (check(ix, iy) && !visitied[iy][ix] && board[currentY][currentX] == board[iy][ix]) {
				visitied[iy][ix]++;
				q.push({ix, iy });
				c++;

				if (store)
					tmpq.push({ -ix, iy });
			}
		}
	}

	return c;

}

// 격자 선택
void choiceBoard() {
	copyBoard();
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int l = 0; l < 3; l++) {
				//회전
				if (l == 0)
					rotate270(j, i);
				else if (l == 1)
					rotate180(j, i);
				else
					rotate90(j, i);

				int sum = 0;
				for (int z = 0; z < 5; z++) {
					for (int x = 0; x < 5; x++) {
						if (!visitied[z][x]) {
							int cnt = bfs(x, z, false);
							if (cnt >= 3) {
								sum += cnt;
							}
						}
					}
				}
				if (sum >= 3) {
					boardsQ.push({ {sum, l}, {-j, -i} });
				}

				reserveBoard();
				init();
			}

		}
	}
}

// 조각 채우기
void batch() {
	while (!fillq.empty()) {
		int x = -fillq.top().first;
		int y = fillq.top().second;
		fillq.pop();
		if (mq.empty())
			return;

		board[y][x] = mq.front();
		mq.pop();

	}
}

int main() {
	cin >> K >> M;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	int num = 0;
	for (int i = 0; i < M; i++) {
		cin >> num;
		mq.push(num);
	}


	// 탐사반복
	while (K--) {
		choiceBoard();
		if (!boardsQ.size())
			break;
		int x = -boardsQ.top().second.first;
		int y = -boardsQ.top().second.second;
		int r = boardsQ.top().first.second;
		if (r == 0)
			rotate270(x, y);
		else if (r == 1)
			rotate180(x, y);
		else
			rotate90(x, y);

        // 유물 연쇄 획득
		int sumValue = 0;
		while (true) {
			sumValue = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (!visitied[i][j]) {
						int cnt = bfs(j, i, true);
						if (cnt >= 3) {
							sumValue += cnt;
                            while(!tmpq.empty()){
                                fillq.push({tmpq.front().first, tmpq.front().second});  // 조각 위치 옮기기(임시에서)
                                tmpq.pop();
                            }
						}else{
                            while(!tmpq.empty())
                                tmpq.pop();
                        }
					}
				}
			}
			if (sumValue == 0){
                init();
                break;
            }

			total += sumValue;

			batch();    // 조각 넣기
			init();
		}
	
		cout << total << " ";
		while (!boardsQ.empty())
			boardsQ.pop();
		total = 0;
	}

	return 0;
}