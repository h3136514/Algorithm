#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int M, S, fx, fy, fd, sx, sy, CNT, num[3], visitied[5][5], smellFish[5][5];
int offer_X[4] = { 0, -1, 0, 1 };
int offer_Y[4] = { -1, 0, 1, 0 };
int offer_fishX[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int offer_fishY[8] = { 0, -1, -1, -1, 0, 1, 1, 1};
priority_queue<pair<int, int>> q;
queue<int> fish[5][5], copyedfish[5][5], movedfish[5][5];
vector<int> v;
vector<pair<int, int>> smellAdd;

// 범위 확인
bool check(int x, int y) {
	return x > 0 && x <= 4 && y > 0 && y <= 4;
}

// 초기화
void init() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++){
            visitied[i][j] = 0;
        }
    }
   
    smellAdd.clear();
}

// 모든 물고기 복제
void copyFish() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (!fish[i][j].empty()) {
				for (int k = 0; k < fish[i][j].size(); k++) {
					int d = fish[i][j].front();
					fish[i][j].pop();

					copyedfish[i][j].push(d);
					fish[i][j].push(d);

				}
			}
		}
	}
}

// 복제 물고기 합치기
void pasteFish() {
    for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			while (!copyedfish[i][j].empty()) {
				fish[i][j].push(copyedfish[i][j].front());
				copyedfish[i][j].pop();
			}
		}
	}
}

// 모든 물고기 이동
void moveFish(){
    for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			while (!fish[i][j].empty()) {
				int d = fish[i][j].front()-1;
				fish[i][j].pop();
                bool moveCheck = false;
                
                for(int k = 0; k < 8; k++){
                    int id = (d - k) < 0 ? 8 + (d - k) :(d - k);    // 반시계반향 확인
                    int ix = j + offer_fishX[id];
                    int iy = i + offer_fishY[id];
                  
                    if(check(ix, iy) && !smellFish[iy][ix] && (sx != ix || sy != iy)){
                        movedfish[iy][ix].push(id+1); // 임시 저장
                        moveCheck = true;
                        break;
                    }
                }

                // 물고기가 이동할 수 없다면
                if(!moveCheck)
                    movedfish[i][j].push(d+1);
			}
		}
	}
    // 임시 저장 => 원래로 옮기기
    for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			while (!movedfish[i][j].empty()) {
				fish[i][j].push(movedfish[i][j].front());
				movedfish[i][j].pop();
			}
		}
	}
}

// 상어가 이동가능한 방향 조합
void dfs(int cnt, int fishNum, int x, int y) {
  
	if (cnt == 3) {
		int idx = 100;
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			sum += num[i] * idx;
			idx /= 10;
		}

		q.push({ fishNum, -sum });

		return;
	}

	for (int i = 0; i < 4; i++) {
		int ix = x + offer_X[i];
		int iy = y + offer_Y[i];

		if (check(ix,iy) && !visitied[iy][ix]) {
			visitied[iy][ix] = 1;
            num[cnt] = i+1;
			dfs(cnt + 1, fishNum + fish[iy][ix].size(), ix, iy);
            visitied[iy][ix] = 0;
		}else if(check(ix,iy)){ // 다시 왔던데 반복 방문
            num[cnt] = i+1;
			dfs(cnt + 1, fishNum, ix, iy);
        }
	}
	
}

// 상어 이동
void moveShark(){
    dfs(0, 0, sx, sy);
    // 방향 추출
    int sum = - q.top().second;
    for(int i = 0; i < 3; i++){
        v.push_back(sum % 10);
        sum /= 10;
    }

    for(int i = 2; i >= 0; i--){
        int d = v[i]-1;
        sx += offer_X[d];
        sy += offer_Y[d];

        // 물고기가 있으면 냄새 설정
        if(!fish[sy][sx].empty())
            smellAdd.push_back({sx, sy});

        while (!fish[sy][sx].empty())
            fish[sy][sx].pop();

    }

    while(!q.empty())
        q.pop();
    v.clear();
}

// 물고기 냄새 갱신(1 감소)
void smellFishDown() {
    for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++){
            if(smellFish[i][j])
                smellFish[i][j]--;
        }
    }
}

// 격자에 있는 물고기 총합 계산
void FishSum(){
    for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++){
           CNT += fish[i][j].size();
        }
    }
}

// 물고기 수 출력
void pri(){
    cout <<"-----------------\n";
    for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++){
           cout << fish[i][j].size() << " ";
        }
        cout << "\n";
    }
    cout <<"-----------------\n";
    cout <<"fishsmell-----------------\n";
    for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++){
           cout << smellFish[i][j] << " ";
        }
        cout << "\n";
    }
    cout <<"-----------------\n";
}

// 물고기 냄새 새로 남김
void addFishSmell(){
    for(int i = 0; i < smellAdd.size(); i++){
        int x = smellAdd[i].first;
        int y = smellAdd[i].second;
        smellFish[y][x] = 2;
    }
}

int main() {
	cin >> M >> S;
	for(int i = 0; i < M; i++){
        cin >> fy >> fx >> fd;
        fish[fy][fx].push(fd);
    }
    cin >> sy >> sx;

    while(S--){
        // 모든 물고기 복제
        copyFish();
        // 모든 물고기 한칸 이동
        moveFish();
        // 상어 연속해서 3칸 이동
        moveShark();
        // 물고기 냄새 갱신
        smellFishDown();
        addFishSmell();

        // 복상한 물고기 합치기
        pasteFish();

        init();
    }
    // 격자에 있는 물고기 수 계산
    FishSum();

    cout << CNT << "\n";

	return 0;
}