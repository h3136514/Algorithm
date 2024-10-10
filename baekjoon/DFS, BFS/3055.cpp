// BFS
#include <iostream>
#include <queue>

#define INF 987654321
using namespace std;
int R, C, DX, DY, SX, SY, visitied[51][51],  waterVisitied[51][51], Min, CNT=0;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
char maps[51][51];
queue<pair<int, pair<int, int>>> q;
queue<pair<int,int>> water;

/*
void printMap(){
    cout << "--------------\n";
     for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << waterVisitied[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "--------------\n";
}
*/

// 초기화
void init(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            visitied[i][j] = 0;
            waterVisitied[i][j] = INF;
        }
    }
}

// 범위 체크
bool check(int x, int y){
    return x >= 0 && x < C && y >= 0 && y < R;
}

// bfs
int bfs(int x, int y){
    int cnt = 0;
    q.push({cnt, {x, y}});
    visitied[y][x] = 1;

    while(!q.empty()){
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        int currentCnt = q.front().first;
        q.pop();

        // 비버굴 도착
        if(currentX == DX && currentY == DY){
            return currentCnt;
        }

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            // 만약 홍수가 지나간다면 그순간이 더커야됨(나중에 지나간 경우)
            if(check(ix, iy) && (maps[iy][ix] == '.'|| maps[iy][ix] == 'D') && maps[iy][ix] != 'X' && waterVisitied[iy][ix] > currentCnt  && !visitied[iy][ix]){
                visitied[iy][ix] = 1;
                q.push({currentCnt+1,{ix, iy}});
            }
        }
    }

    return -1;

}

// 홍수 퍼트리기
void waterSpread(int x, int y){
    int cnt = 0;
    q.push({cnt, {x, y}});
    waterVisitied[y][x] = 0;
 
    while(!q.empty()){
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        int currentCnt = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && (maps[iy][ix] == '.' || maps[iy][ix] == 'S') && waterVisitied[iy][ix] > currentCnt && maps[iy][ix] != 'D' ){
                waterVisitied[iy][ix] = currentCnt; // 현재 지나간 시간(제일 최소)
                q.push({currentCnt+1,{ix, iy}});
            }
        }
    }

}

int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> maps[i][j];
            if(maps[i][j] =='*')
                water.push({j, i});
            if(maps[i][j] =='S'){
                SY = i;
                SX = j;
            }
            if(maps[i][j] =='D'){
                DY = i;
                DX = j;
            }
        }
    }

    init();
    // 모든 홍수 퍼트려보기
    while(!water.empty()){
        int x = water.front().first;
        int y = water.front().second;
        water.pop();

        waterSpread(x, y);
    }
    
    // 탐색
    int minCnt =  bfs(SX, SY);
    if(minCnt == -1)
        cout << "KAKTUS"<< "\n";
    else
        cout << minCnt << "\n";


    return 0;
}