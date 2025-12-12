// https://www.acmicpc.net/problem/25416
#include <iostream>
#include <queue>

using namespace std;
int r, c, targetX, targetY, result, num[5][5], visitied[5][5];
int offer_X[4] = {0, 1, 0, -1};
int offer_Y[4] = {1, 0, -1, 0};
queue<pair<int, pair<int, int>>> q;

bool check(int x, int y){
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

int bfs(int sx, int sy){
    if(sx == targetX && sy == targetY)
        return 0;

    visitied[sy][sx] = 1;
    q.push({0, {sx, sy}});

    while(!q.empty()){
        int currentCnt = q.front().first;
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        q.pop();

        if(currentX == targetX && currentY == targetY)
            return currentCnt;
        
        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && num[iy][ix] != -1){
                visitied[iy][ix] = 1;
                q.push({currentCnt + 1, {ix, iy}});
            }
        }
    }

    return -1;
}

// 빠른 숫자 탐색
int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> num[i][j];
            if(num[i][j] == 1){
                targetX = j;
                targetY = i;
            }
        }
    }
    cin >> r >> c;

    result = bfs(c, r);

    cout << result << "\n";

    return 0;
}