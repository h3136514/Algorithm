#include <iostream>
#include <queue>

using namespace std;
int N, M, startX, startY, num[1001][1001], dist[1001][1001];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
queue<pair<int, pair<int, int>>> q;

// 범위 확인
bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N;
}

// 최단거리
void bfs(){
    q.push({0, {startX, startY}});

    while(!q.empty()){
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        int currentCNT = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && num[iy][ix] != 0 && dist[iy][ix] == 0 ){
                dist[iy][ix] = currentCNT+1;
                q.push({currentCNT+1, {ix, iy}});
            }
        }
    }

    dist[startY][startX] = 0;
}

// 쉬운 최단거리
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> num[i][j];
            if(num[i][j] == 2){
                startX = j;
                startY = i;
            }
        }
    }

    bfs();
    // 도달할 수 없는 위치판별
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(num[i][j] != 2 && num[i][j] != 0 && dist[i][j] == 0){
                dist[i][j] = -1;
            }
        }
    }

    // 출력
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}