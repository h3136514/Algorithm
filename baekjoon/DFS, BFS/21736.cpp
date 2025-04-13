// BFS
#include <iostream>
#include <queue>

using namespace std;
int N, M, targetX, targetY, CNT, visitied[601][601];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
char campus[601][601];
queue<pair<int, int>> q;

bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N;
}

int bfs(int startX, int startY){
    int cnt = 0;
    q.push({ startX, startY});
    visitied[startY][startX] = 1;

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && campus[iy][ix] != 'X'){
                visitied[iy][ix] = 1;
                q.push({ix, iy});
                if(campus[iy][ix] == 'P'){
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

// 헌내기는 친구가 필요해
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> campus[i][j];
            if(campus[i][j] == 'I'){
                targetX = j;
                targetY = i;
            }
        }
    }

    CNT = bfs(targetX, targetY);
    if(CNT)
        cout << CNT << "\n";
    else
        cout << "TT\n";

    return 0;
}