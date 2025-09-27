// https://www.acmicpc.net/problem/19237
#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define INF 1000000000
using namespace std;
int N, M, K, T = 1, board[21][21], tmp[21][21], CNT, a, smellAceess;
int offer_X[4] = {0, 0, -1, 1};
int offer_Y[4] = { -1, 1, 0, 0 };
map<int, pair<int, int>> shark;  //현재 상어 위치
map<int, int> sharkDir; // 현재 상어 방향
vector<pair<int, int>> smell[21][21], copysmell[21][21];	//냄새 상황
vector<int> movePri[401][4];	// 상어별 방향 우선순위
bool live[401];

bool check(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void privBoard() {
	cout << "-----------------\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "-----------------\n";
}


void init() {
	
}

void copySmell() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			copysmell[i][j] = smell[i][j];
		}
	}
}

void copyBoard() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = tmp[i][j];
			tmp[i][j] = 0;
			smell[i][j] = copysmell[i][j];
			copysmell[i][j].clear();
		}
	}
}


//이동 방향 선택
int choiceDir(int num, int x, int y) {
	int d = sharkDir[num];
	vector<int> v(movePri[num][d]);

	// 물고가 냄새가 없는지 우선 확인
	for (int i = 0; i < v.size(); i++) {
		int id = v[i];
		int ix = x + offer_X[id];
		int iy = y + offer_Y[id];
		
		if (check(ix, iy)) {
			int smellCnt = smell[iy][ix][0].second;
			if (smellCnt == 0 || smellAceess > smellCnt) {
				return id;
			}
		}
	}

	// 자신의 냄새가 있는 쪽으로 이동(다 물고기 냄새가 있으므로)
	for (int i = 0; i < v.size(); i++) {
		int id = v[i];
		int ix = x + offer_X[id];
		int iy = y + offer_Y[id];

		if (check(ix, iy)) {
			int smellNum = smell[iy][ix][0].first;
			if (smellNum == num) {
				return id;
			}
		}
	}

	cout << T << "," << num << ": 못찾음\n";
	return 0;
}

// 이동
void move(int num, int x, int y, int d) {
	int ix = x + offer_X[d];
	int iy = y + offer_Y[d];

	if (!check(ix, iy))
		return;


	if (tmp[iy][ix]) {
		live[num] = false;
		CNT--;
		return;
	}

	copysmell[iy][ix][0] = {num, T};
	tmp[iy][ix] = num;
	shark[num] = { ix, iy };
	sharkDir[num] = d;
}


void priSmell() {
	cout << "sss-----------------\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << smell[i][j][0].second << " ";
		}
		cout << "\n";
	}
	cout << "sss-----------------\n";
}

// 어른 상어
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> K;
	// 상어냄새 저장공간 생성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			smell[i][j].resize(1);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];

			if (board[i][j] != 0) {// 상어 위치 등록
				shark[board[i][j]] = { j, i };
				live[board[i][j]] = 1;
				smell[i][j][0] = { board[i][j], 1 }; // 초기 상어 냄새 등록
				CNT++;
			}
		}
	}

	// 상어 방향 입력
	for (int i = 1; i <= M; i++) {
		cin >> a;
		sharkDir[i] = a-1;
	}

	// 우선순위 방향 입력
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			movePri[i][j].resize(4);
			for (int k = 0; k < 4; k++) {
				cin >> a;
				movePri[i][j][k] = a - 1;
			}
		}
	}

	T = 2;
	while (T <= 1001) {
		smellAceess = T - K; // 물고기 냄새 사라짐 여부

		// 물고기 냄새 복사
		copySmell();

		// 상어 이동
		for (int i = 1; i <= M; i++) {
			if (!live[i])
				continue;

			int x = shark[i].first;
			int y = shark[i].second;
			int d = choiceDir(i, x, y);
			move(i, x, y, d);
		}

		copyBoard();	// 이동영역 옮기기


		if (CNT <= 1)
			break;
		
		T++;
	}

	if (T >= 1002)
		T = -1;
	else
		T--;

	cout << T << "\n";

	return 0;
}