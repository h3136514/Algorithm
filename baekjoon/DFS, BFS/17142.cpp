#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321
using namespace std;
int N, M, CNT = 0, virusCnt, board[51][51], visitied[51][51], result = INF;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
vector<pair<int, int>> v, virus;
queue<pair<int, pair<int, int>>> q;

bool check(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visitied[i][j] = 0;
        }
    }
}

void bfs(){
    for(int i = 0; i < v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        visitied[y][x] = 1;
        q.push({0, {x, y}});
    }

    int cnt = CNT, tim = 0;
    while(!q.empty()){
        int currentCnt = q.front().first;
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            int icnt = currentCnt + 1;

            if(check(ix, iy) && !visitied[iy][ix] && (board[iy][ix]== 0 || board[iy][ix]== 2)){
                visitied[iy][ix] = 1;
                if(board[iy][ix]== 0){
                    cnt--;
                    tim = max(tim, icnt);
                }
                
                q.push({icnt, {ix, iy}});
            }
        }
    }

    if(cnt == 0){
        result = min(result, tim);
    }
}

void bactrack(int idx, int cnt){
    if(cnt == M){
        bfs();

        init();
        return;
    }

    for(int i = idx; i < virusCnt; i++){
        v.push_back({virus[i].first, virus[i].second});
        bactrack(i+1, cnt+1);
        v.pop_back();
    }

}

// 연구소 3
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                virus.push_back({j, i});
                virusCnt++;
            }else if(board[i][j] == 0)
                CNT++;
        }
    }
    
    bactrack(0, 0);

    if(result == INF)
        result = -1;
    
    cout << result << "\n";

    return 0;
}