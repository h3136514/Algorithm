#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;
int N, M, board[16][16], visitied[16][16], CNT, TIME = 1;
int offer_X[4] = { 0, -1, 1, 0 };
int offer_Y[4] = { -1, 0, 0, 1 };
vector<pair<int, int>> basecamp, mart;
queue<pair<int, pair<int, int>>> human, basecampQ;
queue<pair<int, int>> closeMart, closeBasecamp;
queue<pair<pair<int, string>, pair<int, int>>> martgoQ;
priority_queue<pair<pair<int, int>, pair<int, int>>> q;

//범위 확인
bool check(int x, int y) {
	return x > 0 && x <= N && y > 0 && y <= N;
}

// 초기화
void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visitied[i][j] = 0;
		}
	}

	while (!martgoQ.empty())
		martgoQ.pop();
	while (!basecampQ.empty())
		basecampQ.pop();
}

//출력(디버깅)
void pri() {
	cout << "----------------------\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "----------------------\n";
	int qsize = human.size();
	for (int i = 0; i < qsize; i++) {
		int d = human.front().first;
		int x = human.front().second.first;
		int y = human.front().second.second;
		human.pop();

		cout << d << " : " << x << "," << y << "\n";
		human.push({ d, {x, y} });
	}

}

// 편의점 경로 탐색
int goMartBfs(int startX, int startY, int targetX, int targetY, int idx) {
	martgoQ.push({ {0, ""}, { startX, startY} });
	visitied[startY][startX] = 1;

	while (!martgoQ.empty()) {
		int currentCNT = martgoQ.front().first.first;
		string currentPath = martgoQ.front().first.second;
		int currentX = martgoQ.front().second.first;
		int currentY = martgoQ.front().second.second;
		martgoQ.pop();

		if (targetX == currentX && targetY == currentY) {
			int d = currentPath[0] - '0';
			
			return d;
		}

		for (int i = 0; i < 4; i++) {
			int ix = currentX + offer_X[i];
			int iy = currentY + offer_Y[i];

			if (check(ix, iy) && !visitied[iy][ix] && board[iy][ix] != 2 && board[iy][ix] != 3) {	// 유효좌표, 방문X, 폐쇄된 베이스 캠프X, 폐쇄된편의점X
				visitied[iy][ix] = 1;
				char c = i + '0';

				martgoQ.push({ {currentCNT+1, currentPath+c}, { ix, iy} });
			}
		}
	}

	return -1;	// 만약에 대비
}

// 베이스캠프  최단경로 찾기
void basecampBfs(int startX, int startY, int targetX, int targetY, int idx) {
	basecampQ.push({ {0}, { startX, startY} });
	visitied[startY][startX] = 1;

	while (!basecampQ.empty()) {
		int currentCNT = basecampQ.front().first;
		int currentX = basecampQ.front().second.first;
		int currentY = basecampQ.front().second.second;
		basecampQ.pop();

		if (targetX == currentX && targetY == currentY) {
			q.push({ {-currentCNT, -startY},{-startX, idx} });
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ix = currentX + offer_X[i];
			int iy = currentY + offer_Y[i];

			if (check(ix, iy) && !visitied[iy][ix] && board[iy][ix] != 2 && board[iy][ix] != 3) {	// 유효좌표, 방문X, 폐쇄된 베이스 캠프X, 폐쇄된편의점X
				visitied[iy][ix] = 1;

				basecampQ.push({ {currentCNT + 1}, { ix, iy} });
			}
		}
	}
}

// 베이스캠프 선택
void chooseBasecamp(int idx) {
	int mx = mart[idx].first;
	int my = mart[idx].second;

	for (int i = 0; i < basecamp.size(); i++) {
		int bx = basecamp[i].first;
		int by = basecamp[i].second;
	
		if (board[by][bx] != 1)
			continue;

		basecampBfs(bx, by, mx, my, i);
		init();
	}

	int bd = q.top().second.second;
	
	while (!q.empty()) {
		q.pop();
	}
		
	
	int bx = basecamp[bd].first;
	int by = basecamp[bd].second;
	board[by][bx] = 3;	//해당 베이스 캠프 폐쇄
	

	// 인간 추가
	human.push({ idx,{bx, by} });
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				basecamp.push_back({ j, i });
			}
		}
	}

	mart.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> mart[i].second >> mart[i].first;
	}

	while (true) {
		// 편의점 반향으로 한칸씩 이동
		if (!human.empty()) {
			int qSize = human.size();
			for (int i = 0; i < qSize; i++){
				int hidx = human.front().first;
				int hx = human.front().second.first;
				int hy = human.front().second.second;
				human.pop();
				
				// 앞으로 갈 방향 구하기
				int d = goMartBfs(hx, hy, mart[hidx].first, mart[hidx].second, hidx);
				hx += offer_X[d];
				hy += offer_Y[d];
				//cout << "go: " << d << " : " << hx << ", " << hy << "\n";

				if (hx == mart[hidx].first && hy == mart[hidx].second) {	// 편의점에 도착했으면
					closeMart.push({ hx, hy });
					CNT++;
				}
				else
					human.push({ hidx, {hx, hy} });

				init();
			}
		}
	
		// 편의점 도착시 해당 편의점 폐쇄
		while (!closeMart.empty()) {
			int mx = closeMart.front().first;
			int my = closeMart.front().second;
			closeMart.pop();
			board[my][mx] = 2;
		}

		
		//t분을 만족하는 사람 투입
		if (TIME <= M) {
			chooseBasecamp(TIME - 1);
		}


		//pri();
		if (CNT == M)	// 모든 사람들이 편의점 도착
			break;

		TIME++;
	}

	cout << TIME << "\n";

	return 0;
}