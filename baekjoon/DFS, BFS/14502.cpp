// https://www.acmicpc.net/problem/14502
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, board[8][8], tmp[8][8], safeCnt, result;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
vector<pair<int, int>> wall;
queue<pair<int, int>> virus;

bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N;
}

int bfs(){
    int cnt = safeCnt;
    while(!virus.empty()){
        int currentX = virus.front().first;
        int currentY = virus.front().second;
        virus.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && tmp[iy][ix] == 0){
                virus.push({ix, iy});
                tmp[iy][ix] = 2;
                cnt--;
            }

        }
    }

    return cnt;
}

void backtracking(int idx, int cnt){
    if(cnt == 3){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(board[i][j] == 2){
                    virus.push({j, i});
                }
                tmp[i][j] = board[i][j];
            }
        }
    
        result = max(result, bfs());
        return;
    }

    for(int i = idx; i < wall.size(); i++){
        int ix = wall[i].first;
        int iy = wall[i].second;
            board[iy][ix] = 1;
            backtracking(i+1, cnt+1);
            board[iy][ix] = 0;
    }
}

// 연구소
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 0){
                wall.push_back({j, i});
            }
        }
    }

    safeCnt = wall.size() - 3;
    backtracking(0, 0);

    cout << result << "\n";

    return 0;
}