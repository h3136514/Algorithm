#include <iostream>
#include <queue>

#define MAX 301
using namespace std;
int T, I, X, Y, CNT, targetX, targetY, visitied[MAX][MAX];
int offersetX[8] = {-1, -2, -1, -2, 1, 2, 1, 2};
int offersetY[8] = {-2, -1, 2, 1, -2, -1, 2, 1};
queue<pair<pair<int, int>, int>> q;

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < I && y < I; 
}

// BFS
int bfs(int x, int y) {
    q.push({{x, y}, 0});
    visitied[y][x] = 1;

    while(!q.empty()) {
        int nextX = q.front().first.first;
        int nextY = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(nextX == targetX && nextY == targetY)
            return cnt;

        for(int i = 0; i < 8; i++) {
            int iX = nextX + offersetX[i];
            int iY = nextY + offersetY[i];
            
            if(check(iX, iY) && !visitied[iY][iX]) {
                visitied[iY][iX] = 1;
                q.push({{iX, iY}, cnt+1});
            }
        }
    }

}

void init() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            visitied[i][j] = 0;
        }
    }

    while(!q.empty()) {
        q.pop();
    }
}

// 나이트의 이동(각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지)
int main() {
    cin >> T;
    while(0 < T--) {
        cin >> I;
        cin >> X >> Y;
        cin >> targetX >> targetY;
        
        CNT = bfs(X, Y);
        cout << CNT << "\n";

        init();
    }

    return 0;
}