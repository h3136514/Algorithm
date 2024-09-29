#include <iostream>
#include <vector>

using namespace std;
int N, M, X, Y, K, direction, num[21][21];
int offer_X[4] = { 1, -1, 0, 0 };
int offer_Y[4] = { 0, 0, -1, 1 };
// 주사위 위치별 동, 서, 북, 남 칸이동
int offer_dice[4][6] ={
    {3, 0, 2, 5, 4, 1}, // 동쪽
    {1, 5, 2, 0, 4, 3}, // 서쪽
    {2, 1, 5, 3, 0, 4}, // 북쪽
    {4, 1, 0, 3, 5, 2}  // 남쪽
};
vector<int> dice(6);  // 주사위

// 범위 체크
bool check(int x, int y) {
	return x >= 0 && x < M && y >= 0 && y < N;
}

// 주사위 이동
void move(int r, vector<int> tmp) {
    for(int i = 0; i < 6; i++) {
        int tmp_idx = offer_dice[r][i];
        dice[i] = tmp[tmp_idx];
    }
}

void diceGame() {
    int dir = direction - 1;
    
	int ix = X + offer_X[dir];
	int iy = Y + offer_Y[dir];
	if (!check(ix, iy))
		return;
	
    move(dir, dice);

	if (num[iy][ix] == 0) { // 이동 칸에 있는 수가 0이면 주사위 바닥 -> 칸 수
		num[iy][ix] = dice[5];	
	}
	else { // 이동 칸에 있는 수가 0이 아니면 칸 수 -> 주사위 바닥, 칸 수 = 0
		dice[5] = num[iy][ix];
		num[iy][ix] = 0;
	}

	X = ix;
	Y = iy;

	cout << dice[0] << "\n";
}


int main() {
	cin >> N >> M >> Y >> X >> K;   // Y, X 순서 주의!
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> direction;

		diceGame();
	}

	return 0;
}
