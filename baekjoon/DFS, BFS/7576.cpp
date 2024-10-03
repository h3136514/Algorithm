// BFS
#include <iostream>
#include <queue>

using namespace std;
int M, N, num, apple, box[1001][1001], visited[1001][1001];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
queue<pair<int, pair<int, int>>> q;

// 범위체크
bool check(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

// bfs
int bfs() {
    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int cnt = q.front().first;
        q.pop();

        for(int i =0; i < 4; i++) {
            int ix = x + offer_X[i];
            int iy = y + offer_Y[i];
            //범위안 && 방문하지X && 안익은 사과
            if(check(ix, iy) && !visited[iy][ix] && box[iy][ix] == 0) {
                box[iy][ix] == 1;
                q.push({cnt+1,{ix, iy}});
                visited[iy][ix] = 1;
                apple--;
            }
        }
        if(apple <= 0)
            return cnt;
    }

    return -1;
}

// 토마토
int main() {
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) {
            cin >> box[i][j];
            if(box[i][j] == 0)
                apple++;
            if(box[i][j] == 1){
                q.push({1, {j, i}});
            }
        }
    }

    if(!apple)
        cout << 0 << "\n";
    else {
        cout << bfs() << "\n";
    }

    return 0;
}
