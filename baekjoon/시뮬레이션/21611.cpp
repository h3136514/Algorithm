#include <iostream>
#include <stack>
#include <queue>

using namespace std;
int N, M, d, s, sharkX, sharkY, CNT[4], board[50][50];
int offer_X[4] = {-1, 0, 1, 0};
int offer_Y[4] = {0, 1, 0, -1};
int blizard_X[6] = { 0, 0, -1, 1, -1, 1};
int blizard_Y[6] = { -1, 1, 0, 0 , -1, 1};
queue<pair<int, int>> q, AB;

// 범위 확인
bool check(int x, int y) {
	return x > 0 && x <= N && y > 0 && y <= N;
}

// 블리자드 마법 시전
void blizard() {
	int x = sharkX;
	int y = sharkY;
	for (int i = 0; i < s; i++) {
		x += blizard_X[d - 1];
		y += blizard_Y[d - 1];
		board[y][x] = 0;
	}
}

// 이동
void move(int x, int y) {
	if(board[y][x] == 0)
		q.push({ x, y });
	else if (!q.empty()) {
		board[q.front().second][q.front().first] = board[y][x];
		board[y][x] = 0;
		q.pop();

		q.push({ x, y });
	}
	
}

// 구슬이동
void moveGoosole() {
	int startX = sharkX, startY = sharkY;
    int id = 3, num = 1;
    // 달팽이 회전
    while(true){
        for(int i = 0; i < 2; i++){
            id = (id == 3) ? 0 : id+1;  // 반시계 회전 

            for(int j = 0; j < num; j++){   // 두번씩
                startX += offer_X[id];
                startY += offer_Y[id];

                if(!check(startX, startY)){
                    while (!q.empty())
		                q.pop();
                    return;
                }

                move(startX, startY);
            }
        }
        num++;

    }
}

bool explos(int color, int cnt, int x, int y) {
	bool changeColor = false;
	if (board[y][x] == color) {
		q.push({ x, y });
	}
	else {
		changeColor = true;
		if (cnt >= 4) {
			while (!q.empty()) {
				board[q.front().second][q.front().first] = 0;
				CNT[color]++;
				q.pop();
			}
		}
		else {
			while (!q.empty()) {
				board[q.front().second][q.front().first] = color;
				q.pop();
			}
		}
	}

	return changeColor;
}

// 구슬 폭발
bool explosGoosole() {
	bool checked = false;
    int startX = sharkX, startY = sharkY;
    int id = 3, num = 1, cnt = 0;
    int color = board[startY][startX-1];

    // 달팽이 회전
    while(true){
        for(int i = 0; i < 2; i++){
            id = (id == 3) ? 0 : id+1;  // 반시계 회전 

            for(int j = 0; j < num; j++){   // 두번씩
                startX += offer_X[id];
                startY += offer_Y[id];

                if(!check(startX, startY)){
                    while (!q.empty())
		                q.pop();

                    return checked;
                }
                
                if (explos(color, cnt, startX, startY)) {
                    if (cnt >= 4)   // 구슬 폭발 유무 확인
                        checked = true;
                    cnt = 1;
                    color = board[startY][startX];
                    q.push({ startX, startY });
                }
                else
                    cnt++;
            }
        }
        num++;
    }
}

// 구슬 변화
void changeGoosole() {
    int startX = sharkX, startY = sharkY;
    int id = 3, num = 1, cnt = 0;
    int color = board[startY][startX-1];
    bool outside = false;
    // 달팽이 회전( A(구슬의 갯수), B(구슬의 색깔) 구하기)
    while(true){
        for(int i = 0; i < 2; i++){
            id = (id == 3) ? 0 : id+1;  // 반시계 회전 

            for(int j = 0; j < num; j++){   // 두번씩
                startX += offer_X[id];
                startY += offer_Y[id];

                if(!check(startX, startY)){
                    outside = true;
                    break;
                }
                
                if (board[startY][startX] == color) {
                    cnt++;
                }
                else {
                    AB.push({ cnt, color });
    
                    cnt = 1;
                    color = board[startY][startX];
                }
    
                board[startY][startX] = 0;
            }

            if(outside)
                break;
        }

        if(outside)
            break;
        num++;
    }

	// 구슬이 없으면
	if (AB.empty())
		return;
	

	startX = sharkX, startY = sharkY;
    id = 3, num = 1;
    int idx = 0;
    cnt = AB.front().first;
	color = AB.front().second;
	AB.pop();

    // 달팽이 회전(A, B 대입)
    while(true){
        for(int i = 0; i < 2; i++){
            id = (id == 3) ? 0 : id+1;  // 반시계 회전 

            for(int j = 0; j < num; j++){   // 두번씩
                startX += offer_X[id];
                startY += offer_Y[id];

                if(!check(startX, startY)){
                    while (!AB.empty())
		                AB.pop();
                    return;
                }

                if (idx == 0) {
                    idx++;
                    board[startY][startX] = cnt;
                }
                else if (idx == 1) {
                    idx = 0;
                    board[startY][startX] = color;
    
                    if (AB.empty()) {
                        return;
                    }
    
                    cnt = AB.front().first;
                    color = AB.front().second;
    
                    AB.pop();
                }
            }
        }
        num++;
    }
}

// 출력(디버그용)
void pri() {
	cout << "-------------------------\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "-------------------------\n";
}

// 초기화
void init() {
	while (!AB.empty())
		AB.pop();
	while (!q.empty())
		q.pop();
}

// 마법사 상어와 블리자드
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
	sharkX = (N + 1) / 2;
	sharkY = (N + 1) / 2;

	for (int j = 0; j < M; j++) {
		cin >> d >> s;

		blizard();
	
		moveGoosole();

		while(explosGoosole())
			moveGoosole();

		changeGoosole();
        
		init();
	}

	cout << CNT[1] + CNT[2] * 2 + CNT[3] * 3 << "\n";

	return 0;
}

// 달팽이 회전 일일이하기
/*
// 이동
void move(int x, int y) {
	if(board[y][x] == 0)
		q.push({ x, y });
	else if (!q.empty()) {
		board[q.front().second][q.front().first] = board[y][x];
		board[y][x] = 0;
		q.pop();

		q.push({ x, y });
	}
	
}

// 구슬이동
void moveGoosole() {
	int startX = sharkX, startY = sharkY, endX = sharkX, endY = sharkY;
	
	while (true) {
		startX += blizard_X[4], startY += blizard_Y[4];
		endX += blizard_X[5], endY += blizard_Y[5];
		if (!check(startX, startY))
			break;

		// 아래 방향
		for (int i = startY + 1; i <= endY; i++)
			move(startX, i);
	
		// 오른쪽 방향
		for (int i = startX + 1; i <= endX; i++)
			move(i, endY);

		// 위 방향
		for (int i = endY - 1; i >= startY; i--)
			move(endX, i);

		// 왼쪽 방향
		for (int i = endX- 1; i >= startX; i--)
			move(i, startY);

	}

	while (!q.empty())
		q.pop();
}

bool explos(int color, int cnt, int x, int y) {
	bool changeColor = false;
	if (board[y][x] == color) {
		q.push({ x, y });
	}
	else {
		changeColor = true;
		if (cnt >= 4) {
			while (!q.empty()) {
				board[q.front().second][q.front().first] = 0;
				CNT[color]++;
				q.pop();
			}
		}
		else {
			while (!q.empty()) {
				board[q.front().second][q.front().first] = color;
				q.pop();
			}
		}
	}

	return changeColor;
}

// 구슬 폭발
bool explosGoosole() {
	bool checked = false;
	int startX = sharkX, startY = sharkY, endX = sharkX, endY = sharkY;
	int color = board[startX+1][startX];
	int cnt = 0;

	while (true) {
		startX += blizard_X[4], startY += blizard_Y[4];
		endX += blizard_X[5], endY += blizard_Y[5];
		if (!check(startX, startY))
			break;

		// 아래 방향
		for (int i = startY + 1; i <= endY; i++) {
			if (explos(color, cnt, startX, i)) {
				if (cnt >= 4)
					checked = true;
				cnt = 1;
				color = board[i][startX];
				q.push({ startX, i });
			}
			else
				cnt++;
		}

		// 오른쪽 방향
		for (int i = startX + 1; i <= endX; i++) {
			if (explos(color, cnt, i, endY)) {
				if (cnt >= 4)
					checked = true;
				cnt = 1;
				color = board[endY][i];
				q.push({ i, endY });
			}
			else
				cnt++;
		}
			
		// 위 방향
		for (int i = endY - 1; i >= startY; i--) {
			if (explos(color, cnt, endX, i)) {
				if (cnt >= 4)
					checked = true;
				cnt = 1;
				color = board[i][endX];
				q.push({ endX, i });
			}
			else
				cnt++;
		}

		// 왼쪽 방향
		for (int i = endX - 1; i >= startX; i--) {
			if (explos(color, cnt, i, startY)) {
				if (cnt >= 4)
					checked = true;
				cnt = 1;
				color = board[startY][i];
				q.push({ i, startY });
			}
			else
				cnt++;
		}
	}

	while (!q.empty())
		q.pop();


	return checked;
}

// 구슬 변화
void changeGoosole() {
	int startX = sharkX, startY = sharkY, endX = sharkX, endY = sharkY;
	int color = board[startY ][startX-1];
	int cnt = 0;
	// A(구슬의 갯수), B(구슬의 색깔) 구하기
	while (true) {
		startX += blizard_X[4], startY += blizard_Y[4];
		endX += blizard_X[5], endY += blizard_Y[5];
		if (!check(startX, startY))
			break;

		// 아래 방향
		for (int i = startY + 1; i <= endY; i++) {
			if (board[i][startX] == color) {
				cnt++;
			}
			else {
				AB.push({ cnt, color });

				cnt = 1;
				color = board[i][startX];
			}

			board[i][startX] = 0;
		}

		// 오른쪽 방향
		for (int i = startX + 1; i <= endX; i++) {
			if (board[endY][i] == color) {
				cnt++;
			}
			else{
				AB.push({ cnt, color });

				cnt = 1;
				color = board[endY][i];
			}

			board[endY][i] = 0;
		}

		// 위 방향
		for (int i = endY - 1; i >= startY; i--) {
			if (board[i][endX] == color) {
				cnt++;
			}
			else {
				AB.push({ cnt, color });

				cnt = 1;
				color = board[i][endX];
			}

			board[i][endX] = 0;
		}

		// 왼쪽 방향
		for (int i = endX - 1; i >= startX; i--) {
			if (board[startY][i] == color) {
				cnt++;
			}
			else {
				AB.push({ cnt, color });

				cnt = 1;
				color = board[startY][i];
			}

			board[startY][i] = 0;
		}
	}
	
	if (cnt != 1 && color != 0) {
		AB.push({ cnt, color });
	}
	
	if (AB.empty())
		return;
	

	startX = sharkX, startY = sharkY, endX = sharkX, endY = sharkY;
	// A, B 대입
	int idx = -1;
	while (true) {
		startX += blizard_X[4], startY += blizard_Y[4];
		endX += blizard_X[5], endY += blizard_Y[5];
		if (!check(startX, startY)|| idx == 3)
			break;

		if (idx == -1) {
			cnt = AB.front().first;
			color = AB.front().second;

			AB.pop();
			
			idx = 0;
		}

		// 아래 방향
		for (int i = startY + 1; i <= endY; i++) {
			if (idx == 0) {
				idx++;
				board[i][startX] = cnt;
			}
			else if (idx == 1) {
				idx = 0;
				board[i][startX] = color;

				if (AB.empty()) {
					idx = 3;
					break;
				}

				cnt = AB.front().first;
				color = AB.front().second;

				AB.pop();
			}
		}

		if (idx == 3)
			break;

		// 오른쪽 방향
		for (int i = startX + 1; i <= endX; i++) {
			if (idx == 0) {
				idx++;
				board[endY][i] = cnt;
			}
			else if (idx == 1) {
				idx = 0;
				board[endY][i] = color;

				if (AB.empty()) {
					idx = 3;
					break;
				}

				cnt = AB.front().first;
				color = AB.front().second;

				AB.pop();
			}
		}

		if (idx == 3)
			break;

		// 위 방향
		for (int i = endY - 1; i >= startY; i--) {
			if (idx == 0) {
				idx++;
				board[i][endX] = cnt;
			}
			else if (idx == 1) {
				idx = 0;
				board[i][endX] = color;

				if (AB.empty()) {
					idx = 3;
					break;
				}

				cnt = AB.front().first;
				color = AB.front().second;

				AB.pop();
			}
		}

		if (idx == 3)
			break;

		// 왼쪽 방향
		for (int i = endX - 1; i >= startX; i--) {
			if (idx == 0) {
				idx++;
				board[startY][i] = cnt;
			}
			else if (idx == 1) {
				idx = 0;
				board[startY][i] = color;

				if (AB.empty()) {
					idx = 3;
					break;
				}

				cnt = AB.front().first;
				color = AB.front().second;

				AB.pop();
			}
		}

	}

	while (!AB.empty())
		AB.pop();
}
*/