// BFS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, CNT = 1, brige = 10001, land[101][101], landVisitied[101][101], startVisitied[101][101];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
queue<pair<int, pair<int,int>>> brigeq;
vector<pair<int, int>> V[10003];

// 범위 체크
bool check(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

// 방문 초기화
void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            landVisitied[i][j] = 0;;
        }
    }
}

// 섬 구분 & 가장자리를 찾는 BFS 
void edgeBfs(int startX, int startY){
    q.push({startX, startY});
    land[startY][startX] = ++CNT;

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && land[iy][ix] == 1){
                land[iy][ix] = CNT; // 섬 구분
                q.push({ix, iy});
            }else if(check(ix, iy) && land[iy][ix] == 0 && startVisitied[currentY][currentX] == 0){
                startVisitied[currentY][currentX] = 1;
                V[CNT].push_back({currentX, currentY});
            }
        }
    }
}

// 섬을 잇는 가장 짧은 다리의 길이 구하기
void bfs(int startX, int startY){
    brigeq.push({0, {startX, startY}});
    landVisitied[startY][startX] = 1;
    int cnt = land[startY][startX];

    while(!brigeq.empty()){
        int currentCNT = brigeq.front().first;
        int currentX = brigeq.front().second.first;
        int currentY = brigeq.front().second.second;
        brigeq.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && land[iy][ix] == 0 && landVisitied[iy][ix] == 0){
                landVisitied[iy][ix] = 1;
                brigeq.push({currentCNT+1, {ix, iy}});
            }else if(check(ix, iy) && land[iy][ix] != cnt && landVisitied[iy][ix] == 0){
                brige = min(brige, currentCNT);
            }
        }
    }
}

// 다리 만들기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> land[i][j];
        }
    }

    // 섬 구분 && 섬 모서리 구하기
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(land[i][j] == 1){
                edgeBfs(j, i);
            }
        }
    }

    // 섬의 모서리에서 다른 섬 탐색시작
    for(int i = 2; i <= CNT; i++){
        for(int j = 0; j < V[i].size(); j++){
            bfs(V[i][j].first, V[i][j].second);
            init();
        }
    }

    cout << brige << "\n";

    return 0;
}