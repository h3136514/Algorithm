// BFS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, CNT, safeCNT, num[9][9], tmp[9][9], visitied[9][9];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
vector<pair<int, int>> wall;
queue<pair<int, int>> virus;

// 범위체크
bool check(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

// bfs(바이러스 퍼지기)
int bfs(){
    int cnt = CNT;
    while(!virus.empty()) {
        int currentX = virus.front().first;
        int currentY = virus.front().second;
        virus.pop();

        for(int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            
            if(check(ix, iy) && tmp[iy][ix] == 0) {
                tmp[iy][ix] = 2;
                cnt--;
                virus.push({ix, iy});
            }
        }
    }

    return cnt;
}

// 백트래킹(벽3개를 추가하는 모든 경우)
void dfs(int cnt, int idx) {
    if(cnt == 3) {
        // 임시 저장소 복사
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++) {
                if(num[i][j] == 2) {    // 바이러스
                    virus.push({j, i}); 
                }
                tmp[i][j] = num[i][j];
            }
        }

        safeCNT = max(safeCNT, bfs());  // 안전 영역 크기의 최댓값
        return;
    }

    // 중복 경우 방지(이전값 idx)
    for(int i = idx; i < wall.size(); i++) {
        int x = wall[i].first;
        int y = wall[i].second;
        
        if(!visitied[y][x]) {
            visitied[y][x] = 1;
            num[y][x] = 1;
            dfs(cnt+1, idx+1);
            visitied[y][x] = 0;
            num[y][x] = 0;
        }
    }

}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> num[i][j];
            if(num[i][j] == 0) {    // 벽 후보
                wall.push_back({j, i}); 
            }
        }
    }

    CNT = wall.size() - 3; // 최대 안전구역 갯수
    dfs(0, 0);  

    cout << safeCNT << "\n";

    return 0;
}
