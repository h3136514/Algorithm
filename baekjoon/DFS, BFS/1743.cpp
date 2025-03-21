// BFS
#include <iostream>
#include <queue>

using namespace std;
int N, M, K, r, c, CNT, waste[101][101], visit[101][101];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

// 범위 체크
bool check(int x, int y){
    return x > 0 && y > 0 && x <= M && y <= N;
}

// bfs(뭉친 음식물쓰레기 크기)
void bfs(int startX, int startY){
    visit[startY][startX] = 1;
    q.push({startX, startY});
    int cnt = 1;

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && waste[iy][ix] && !visit[iy][ix]){
                visit[iy][ix] = 1;
                cnt++;

                q.push({ix, iy});
            }
        }
    }  

    CNT = max(CNT, cnt);
}

// 음식물 피하기
int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        cin >> r >> c;
        waste[r][c] = 1;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(waste[i][j] == 1 && !visit[i][j]){
                bfs(j, i);
            }
        }
    }

    cout << CNT << "\n";

    return 0;
}