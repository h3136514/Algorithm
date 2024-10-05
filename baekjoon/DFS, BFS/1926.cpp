// BFS
#include <iostream>
#include <queue>

using namespace std;
int N, M, CNT, pictureSize, num[501][501], visitied[501][501];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

// 범위 체크
bool check(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

// bfs (같은 그림인지 탐색)
void bfs(int x, int y) {
    q.push({x, y});
    visitied[y][x] = 1;
    CNT++;  // 전체 그림 수 증가
    int cnt = 1;

    while(!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && num[iy][ix] == 1 && !visitied[iy][ix]) {
                visitied[iy][ix] = 1;
                q.push({ix, iy});
                cnt++;  // 그림 조각 증가
            }

        }
    }
    // 최대 그림 조각 수 갱신
    pictureSize = max(pictureSize, cnt);
}

// 그림
int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
       for(int j = 0; j < M; j++) {
        cin >> num[i][j];
       }  
    }

    for(int i = 0; i < N; i++) {
       for(int j = 0; j < M; j++) {
            if(num[i][j] == 1 && !visitied[i][j])
                bfs(j, i);
       }  
    }

    cout << CNT << "\n";
    cout << pictureSize << "\n";

    return 0;
}
