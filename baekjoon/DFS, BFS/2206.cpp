// BFS
#include <iostream>
#include <queue>
#include <string>

#define MAX 987654321
using namespace std;
int N, M, dist = MAX;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
string map[1001];
bool Wallvisitied[1001][1001], visitied[1001][1001];    // 벽을 이미깬경우, 안깬 경우 방문기록
queue<pair<int, pair<int, int>>> q;

// 범위 확인
bool check(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

// bfs(벽 부숴보고 이동하기)
int bfs(int startX, int startY) {
    int cnt = 1;    
    q.push({cnt, {startX, startY}});
    visitied[startY][startX] = true;

    while(!q.empty()) {
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        int currentCNT = q.front().first;
        q.pop();

        if(currentX == M-1 && currentY == N-1){
            if(currentCNT < 0)  //음수일 때(벽을 깼을 경우)
                dist = min(dist, -currentCNT);
            else    //0, 양수일 때(벽을 안깬 경우)
                dist = min(dist, currentCNT);
        }

        for(int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            // 벽을 하나 깨보는 경우
            if(check(ix, iy) && currentCNT >= 0 && !Wallvisitied[iy][ix] && map[iy][ix] == '1'){
                Wallvisitied[iy][ix] = true;
                q.push({-(currentCNT+1), {ix, iy}});
            }
            
            if(check(ix, iy) && !visitied[iy][ix] && map[iy][ix] == '0' && currentCNT >= 0 ) {  // 벽을 안깬 경우
                visitied[iy][ix] = true;
                q.push({currentCNT+1, {ix, iy}});
            }else if(check(ix, iy) && !Wallvisitied[iy][ix] && map[iy][ix] == '0' && currentCNT < 0){ // 벽을 이미 하나깬 경우
                Wallvisitied[iy][ix] = true;  
                q.push({currentCNT-1, {ix, iy}});
            }
        }
    }

    return MAX; //(N, M)의 위치까지 이동 X
}

// 벽 부수고 이동하기(한 개의 벽을 부수고 이동할 수 있을때(필수X) 최단 경로를 구해라)
int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> map[i];
    }

    // 벽 안부수고 이동
    dist = min(dist, bfs(0, 0));
  
    if(dist == MAX)
        cout << -1 << "\n";
    else
        cout << dist << "\n";

    return 0;
}
