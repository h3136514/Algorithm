#include <iostream>
#include <queue>
#include <string>

using namespace std;
int M, N, visitied[1001][1001];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
string board[1001];
bool perc;
queue<pair<int, int>> q;

bool check(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void bfs(int startX, int startY){
    visitied[startY][startX] = 1;
    q.push({startX, startY});

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && board[iy][ix] == '0'){
                visitied[iy][ix] = 1;
                q.push({ix, iy});
            }
        }
    }
}

// 침투
int main(){
    cin >> M >> N;
    for(int i = 0; i < M; i++){
        cin >> board[i];
    }

    // 격자의 위쪽에서 출발(전류가 잘 통하는 흰색 '0')
    for(int i = 0; i < N; i++){
        if(!visitied[0][i] && board[0][i] == '0'){
            bfs(i, 0);
        }
    }

    // 격자의 아랫쪽에 도달했는지
    for(int i = 0; i < N; i++){
        if(visitied[M-1][i]){
            perc = true;
            break;
        }
    }

    if(perc)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
