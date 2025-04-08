#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
int N, M, Sr, Sc, Er, Ec, Ac, Ar, CNT, distSum, stormSum, attackSum, board[51][51], visitied[51][51], ragerBoard[51][51], copyedBoard[51][51];
int offer_X[4] = { 0, 0, -1, 1 };
int offer_Y[4] = { -1, 1, 0, 0 };
string dist;
queue<pair<string, pair<int, int>>> q;
queue<pair<int, int>> ragerQ, shawdowQ;
queue<int> warrior[51][51], copyedWarrior[51][51];
priority_queue<pair<int, int>> distQ;
vector<pair<int, int>> V[4];
map<int, int> warriorState; // 1. 활동, 2. 돌, 0. 죽음

// 범위 체크
bool check(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

// 범위 초기화
void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visitied[i][j] = 0;
			ragerBoard[i][j] = 0;
		}
	}

	while (!q.empty())
		q.pop();
}

void initNum(){
	distSum = 0, stormSum = 0, attackSum = 0;
}
// 메두사 시선 출력
void priRager() {
	cout << "--------\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ragerBoard[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "--------\n";
}


// 메두사 시선 출력
void priVist() {
	cout << "--------방문----\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visitied[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "--------\n";
}

// 메두사 최단 경로 탐색
bool bfs() {
	q.push({ "", {Sc, Sr} });
	visitied[Sr][Sc] = 1;

	while (!q.empty()) {
		int currentX = q.front().second.first;
		int currentY = q.front().second.second;
		string currentSumDirection = q.front().first;
		q.pop();

		if (Ec == currentX && Er == currentY) {
			dist = currentSumDirection;

			return true;
		}

		for (int i = 0; i < 4; i++) {
			int ix = currentX + offer_X[i];
			int iy = currentY + offer_Y[i];

			if (check(ix, iy) && !board[iy][ix] && !visitied[iy][ix]) {
				char dir = (i + '0');
				string iSumDirection = currentSumDirection + dir;
				visitied[iy][ix] = 1;
				q.push({ iSumDirection, {ix, iy} });
			}

		}
	}

	return false;
}
// 전사 확인(만나면 죽음)
void checkMeetWarrior(int x, int y) {
	while (!warrior[y][x].empty()) {
		int idx = warrior[y][x].front();
		warrior[y][x].pop();

		warriorState[idx] = 0;
	}
}
// 그림자 설정
void shadowsBFS(int x, int y, int d1, int d2) {
	shawdowQ.push({ x, y });

	while (!shawdowQ.empty()) {
		int currentX = shawdowQ.front().first;
		int currentY = shawdowQ.front().second;
		shawdowQ.pop();

		int ix1, iy1, ix2, iy2;
		ix1 = currentX + offer_X[d1];
		iy1 = currentY + offer_Y[d1];
		if (check(ix1, iy1) && !visitied[iy1][ix1]) {
			visitied[iy1][ix1] = 2;
			shawdowQ.push({ ix1, iy1 });
		}
		if (d2 != -1) {
			ix2 = ix1 + offer_X[d2];
			iy2 = iy1 + offer_Y[d2];
			if (check(ix2, iy2) && !visitied[iy2][ix2]) {
				visitied[iy2][ix2] = 2;
				shawdowQ.push({ ix2, iy2 });
			}
		}
	}
}

// 그림자 탐색
void shadows(int dir, int x, int y) {
	// 전사 그림자 탐색
	if (x == Sc || y == Sr)
		shadowsBFS(x, y, dir, -1);
	else {
		if (dir < 2) {
			if (x < Sc)
				shadowsBFS(x, y, dir, 2);
			else
				shadowsBFS(x, y, dir, 3);
		}
		else {
			if (y < Sr)
				shadowsBFS(x, y, dir, 0);
			else
				shadowsBFS(x, y, dir, 1);
		}

	}

	// 전사 돌로 상태 변환
	for (int i = 0; i < warrior[y][x].size(); i++) {
		int idx = warrior[y][x].front();
		warrior[y][x].pop();
		warriorState[idx] = 2;
		warrior[y][x].push(idx);
	}

}


//메두사의 시선
void stoneBfs(int dir) {
	int cnt = 0;
	ragerQ.push({ Sc, Sr });
	visitied[Sr][Sc] = 1;

	while (!ragerQ.empty()) {
		int currentX = ragerQ.front().first;
		int currentY = ragerQ.front().second;
		ragerQ.pop();

		int ix1, iy1;
		ix1 = currentX + offer_X[dir];
		iy1 = currentY + offer_Y[dir];
		if (check(ix1, iy1) && !visitied[iy1][ix1]) {
			visitied[iy1][ix1] = 1;
			ragerBoard[iy1][ix1] = 1;

			// 전사가 있으면
			if (!warrior[iy1][ix1].empty()) {
				shadows(dir, ix1, iy1);
				cnt += warrior[iy1][ix1].size();
			}else
				ragerQ.push({ ix1, iy1 });
		}
		// 양쪽 방향
		int ix2 = ix1, ix3 = ix1, iy2 = iy1, iy3 = iy1;
		if (dir < 2) {
			ix2 += offer_X[2];
			ix3 += offer_X[3];
		}
		else {
			iy2 += offer_Y[0];
			iy3 += offer_Y[1];
		}

		if (check(ix2, iy2) && !visitied[iy2][ix2]) {
			visitied[iy2][ix2] = 1;
			ragerBoard[iy2][ix2] = 1;

			// 전사가 있으면
			if (!warrior[iy2][ix2].empty()) {
				shadows(dir, ix2, iy2);
				cnt += warrior[iy2][ix2].size();
			}
			else
				ragerQ.push({ ix2, iy2 });
		}
		if (check(ix3, iy3) && !visitied[iy3][ix3]) {
			visitied[iy3][ix3] = 1;
			ragerBoard[iy3][ix3] = 1;

			// 전사가 있으면
			if (!warrior[iy3][ix3].empty()) {
				shadows(dir, ix3, iy3);
				cnt += warrior[iy3][ix3].size();
			}
			else
				ragerQ.push({ ix3, iy3 });
		}

	}


	distQ.push({ cnt, -dir });
}

//이동거리 계산 
int accuratrDist(int x, int y) {
	return abs(x - Sc) + abs(y - Sr);
}

// 전사들 이동
void moveWarrior() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!warrior[i][j].empty()) {
				// 돌이된 전사 
				if (ragerBoard[i][j] == 1) {
					while (!warrior[i][j].empty()) {
						copyedWarrior[i][j].push(warrior[i][j].front());
						warrior[i][j].pop();
					}
				}
				else {// 돌이 안된 전사
					int distance = accuratrDist(j, i);
					int d = -1;
					for (int l = 0; l < 4; l++) {
						int ix = j + offer_X[l];
						int iy = i + offer_Y[l];

						if (check(ix, iy) && !ragerBoard[iy][ix]) {
							int idistance = accuratrDist(ix, iy);
							if (distance > idistance) {
								distance = idistance;
								d = l;
							}
						}
					}

					if (d != -1) {
						int ix = j + offer_X[d];
						int iy = i + offer_Y[d];
						int distancei = accuratrDist(ix, iy);
						int di = -1;

						for (int l = 3; l >= 0; l--) {
							int ix2 = ix + offer_X[l];
							int iy2 = iy + offer_Y[l];

							if (check(ix2, iy2) && !ragerBoard[iy2][ix2]) {
								int distancei2 = accuratrDist(ix2, iy2);
								if (distancei > distancei2) {
									distancei = distancei2;
									di = l;
								}
							}
						}
						// 한번만 이동
						if (di == -1) {
							while (!warrior[i][j].empty()) {
								copyedWarrior[iy][ix].push(warrior[i][j].front());
								warrior[i][j].pop();
								distSum++;
							}
						}
						else { // 두번이동
							int ix2 = ix + offer_X[di];
							int iy2 = iy + offer_Y[di];
							while (!warrior[i][j].empty()) {
								copyedWarrior[iy2][ix2].push(warrior[i][j].front());
								warrior[i][j].pop();
								distSum += 2;
							}
						}
					}
					else {
						while (!warrior[i][j].empty()) {
							copyedWarrior[i][j].push(warrior[i][j].front());
							warrior[i][j].pop();
						}
					}


				}

				
			}
		}
	}
	// 위치 옮기기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!copyedWarrior[i][j].empty()) {
				while (!copyedWarrior[i][j].empty()) {
					warrior[i][j].push(copyedWarrior[i][j].front());
					copyedWarrior[i][j].pop();
				}
			}
		}
	}
}

// 전사들 공격확인
void checkAttack() {
	while (!warrior[Sr][Sc].empty()) {
		attackSum++;
		warriorState[warrior[Sr][Sc].front()] == 0;
		warrior[Sr][Sc].pop();
	}
}


int main() {
	cin >> N >> M;
	cin >> Sr >> Sc >> Er >> Ec;
	for (int i = 0; i < M; i++) {
		cin >> Ar >> Ac;
		warriorState[i + 1] = 1;	// 상태 설정
		warrior[Ar][Ac].push(i + 1);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	// 초기에 메두산 최단경로 계산
	if (CNT++ == 0) {
		if (!bfs()) {	// 공원으로 못가는 경우
			cout << "-1\n";
			return 0;
		}
	}
	init();
	// cout << "경로:" << dist << "\n";

	// 최단 경로 한칸식 이동
	for (int i = 0; i < dist.size() - 1; i++) {
		int dir = dist[i] - '0';
		Sc += offer_X[dir];
		Sr += offer_Y[dir];

		checkMeetWarrior(Sc, Sr);

		// 메두사의 시선
		for (int j = 0; j < 4; j++) {
			stoneBfs(j);
			init();
		}

		// 메두사 시선 결정
		stormSum += distQ.top().first;
		stoneBfs(-distQ.top().second);
		while (!distQ.empty())
			distQ.pop();

		//priRager();
		//priVist();

		// 전사들 이동
		moveWarrior();
		// 전사들 공격
		checkAttack();


		cout << distSum << " " << stormSum << " " <<attackSum << "\n";
		initNum();
		init();

	}

	cout << "0\n";

	return 0;
}