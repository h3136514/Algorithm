// BFS
#include <iostream>
#include <queue>
#include <string>

using namespace std;
int N, cnt1, cnt2, visited[101][101], colorVisited[101][101];
int offer_X[4] ={1, 0, -1, 0};
int offer_Y[4] ={0, 1, 0, -1};
string color[101];
queue<pair<int, int>> q1;
queue<pair<int, int>> q2;

bool check(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// 적록색약이 아닌 사람이 봤을 때
void bfs1(int startX, int startY) {
    q1.push({startX, startY});
    visited[startY][startX] = 1;

    while(!q1.empty()) {
        int currentX = q1.front().first;
        int currentY = q1.front().second;
        q1.pop();

        for(int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            if(check(ix, iy) && !visited[iy][ix] && color[currentY][currentX] == color[iy][ix]) {
                visited[iy][ix] = 1;
                q1.push({ix, iy});
            }
        }
    }

}

// 적록색약인 사람이 봤을 때
void bfs2(int startX, int startY) {
    q2.push({startX, startY});
    colorVisited[startY][startX] = 1;

    while(!q2.empty()) {
        int currentX = q2.front().first;
        int currentY = q2.front().second;
        char col = color[currentY][currentX];
        q2.pop();

        for(int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            if(check(ix, iy) && !colorVisited[iy][ix] && ((col == 'B' && color[iy][ix] == 'B') || (col != 'B' && color[iy][ix] != 'B'))) {
                colorVisited[iy][ix] = 1;
                q2.push({ix, iy});
            }
        }
    }

}

// 적록색약
int main() {
    cin >> N;
    for(int i =0; i < N; i++)
        cin >> color[i];

    for(int i =0; i < N; i++) {
        for(int j =0; j < N; j++) {
            if(!visited[i][j]) {
                bfs1(j, i);
                cnt1++;
            }
            if(!colorVisited[i][j]) {
                bfs2(j, i);
                cnt2++;
            }
        }
    }

    cout << cnt1 << " " << cnt2 << "\n"; 

    return 0;
}