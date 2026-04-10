// https://www.acmicpc.net/problem/17086
#include <iostream>
#include <queue>

using namespace std;
int N, M, num[51][51], visitied[51][51], dist;
int offer_X[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int offer_Y[8] = {0, 1, 0, -1, 1, -1, 1, -1};
queue<pair<pair<int, int>, int>> q;

void init(){
    while(!q.empty())
        q.pop();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visitied[i][j] = 0;
        }
    }
}

bool check(int x, int y){
    return x >= 0 && y >= 0 && x < M && y < N;
}

int bfs(int startX, int startY){
    visitied[startY][startX] = 1;
    q.push({{startX, startY}, 0});

    while(!q.empty()){
        int currentX = q.front().first.first;
        int currentY = q.front().first.second;
        int currentCnt = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            int icnt = currentCnt + 1;

            if(check(ix, iy) && !visitied[iy][ix]){
                if(num[iy][ix])
                    return icnt;

                visitied[iy][ix] = 1;
                q.push({{ix, iy}, icnt});
            }
        }
    }

    return 0;
}

// 아기 상어 2
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> num[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(num[i][j] == 0){
                int cnt  = bfs(j, i);
                dist = max(dist, cnt);
                init();
            }
        }
    }

    cout << dist << "\n";

    return 0;
}

