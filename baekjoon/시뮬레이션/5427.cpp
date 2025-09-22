#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321
using namespace std;
int T, w, h, fireVisitied[1001][1001], visitied[1001][1001], startX, startY, CNT = INF;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
char board[1001][1001];
vector<pair<int, int>> fire;
queue<pair<int, pair<int, int>>> q;

// 초기화
void init(){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            fireVisitied[i][j] = INF;
            visitied[i][j] = 0;
        }
    }
    fire.clear();
    CNT = INF;
}

// 범위확인
bool check(int x, int y){
    return x >= 0 && x < w && y >= 0 && y < h; 
}

// 불 번지기
void fireBfs(){
    for(int i = 0; i < fire.size(); i++){
        int x = fire[i].first;
        int y = fire[i].second;
        fireVisitied[y][x] = 0;

        q.push({0, {x, y}});
    }

    while(!q.empty()){
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        int currentCnt = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            int icnt = currentCnt + 1;

            if(check(ix, iy) && board[iy][ix] == '.' && fireVisitied[iy][ix] > icnt){
                fireVisitied[iy][ix] = icnt;
                q.push({icnt, {ix, iy}});
            }
        }

    }

}

// 탈출구 탐색
void bfs(){
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
            int icnt = currentCnt + 1;

            if(!check(ix, iy)){
                CNT = min(CNT, icnt);
            }

            if(check(ix, iy) && board[iy][ix] == '.' && !visitied[iy][ix] && fireVisitied[iy][ix] > icnt){
                visitied[iy][ix] = 1;
                q.push({icnt, {ix, iy}});
            }
        }

    }

}

// 불
int main(){
    cin >> T;
    while(T--){
        cin >> w >> h;

        init();

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> board[i][j];

                if(board[i][j] == '@'){
                    startX = j;
                    startY = i;
                }

                if(board[i][j] == '*'){
                    fire.push_back({j, i});
                }
            }
        }

        fireBfs();
        bfs();

        if(CNT == INF)
            cout << "IMPOSSIBLE\n";
        else
            cout << CNT << "\n";

    }
    
    return 0;
}