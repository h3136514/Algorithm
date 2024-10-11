// BFS
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
int N, M, visitied[51][51], CNT = 0;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
string land[51];
vector<pair<int, int>> v;   // 보물들 위치 저장
queue<pair<int, pair<int, int>>> q;

// 범위 체크
bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N;
}

// 초기화
void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visitied[i][j] = 0;
        }
    }
}

// bfs(주변 육지 탐색)
int bfs(int startX, int startY){
    q.push({0, {startX, startY}});
    visitied[startY][startX] = 1;

    while(!q.empty()){
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        int currentCnt = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && land[iy][ix] == 'L' && !visitied[iy][ix]){
                visitied[iy][ix] = 1;
                CNT = max(CNT, currentCnt+1);   // 제일 먼 최단 경로 갱신
                q.push({currentCnt+1, {ix, iy}});
            }
        }
    }

    return 0;
}

// 보물섬
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> land[i];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(land[i][j] == 'L'){
                v.push_back({j, i});
            }
        }
    }

    for(int i = 0; i < v.size(); i++){
        int startLx = v[i].first;
        int startLy = v[i].second;
 
        CNT = max(CNT, bfs(startLx, startLy));  
        init();
    }

    cout << CNT << "\n";

    return 0;
}

