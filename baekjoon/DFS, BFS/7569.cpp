// BFS
#include <iostream>
#include <queue>

using namespace std;
int M, N, H, apple, box[101][101][101];
int offer_X[6] = {0, 0, -1, 1, 0, 0};
int offer_Y[6] = {0, 0, 0, 0, 1, -1};
int offer_H[6] = {1, -1, 0, 0, 0, 0};
queue<pair<pair<int, int>, pair<int, int>>> q;

// 유효한 좌표인지 확인
bool check(int x, int y, int h) {
    return x >= 0 && x < M && y >= 0 && y < N && h >= 0 && h < H;
}

// bfs(주변 토마토 익히기)
int bfs() {
    while(!q.empty()) {
        int cnt = q.front().first.first;
        int h = q.front().first.second;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        for(int i= 0; i < 6; i++) {
            int ix = x + offer_X[i];
            int iy = y + offer_Y[i];
            int ih = h + offer_H[i];
            //범위안 && 안익은 토마토(익은으로바꿈 => 다시방문X)
            if(check(ix, iy, ih) && box[ih][iy][ix] == 0) {
                box[ih][iy][ix] = 1;
                q.push({{cnt+1, ih}, {iy, ix}});
                apple--;
            }
        }

        if(apple == 0)
            return cnt;
    }

    return -1;
}

// 토마토2
int main(){
    // 입력
    cin >> M >> N >> H;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                if(box[i][j][k] == 0)
                    apple++;
                if(box[i][j][k] == 1)
                    q.push({{1, i}, {j, k}});
            }
        }
    }

    if(apple == 0)
        cout << 0 << "\n";
    else
        cout << bfs() << "\n";

    return 0;
}