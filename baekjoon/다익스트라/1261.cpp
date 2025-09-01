#include <iostream>
#include <queue>
#include <string>

#define INF 987654321
using namespace std;
int N, M, dp[101][101];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
string s[101];
priority_queue<pair<int, pair<int, int>>> q;

bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N;
}

int dijkstra(){
    dp[0][0] = 0;
    q.push({0, {0, 0}});

    while(!q.empty()){
        int currentX = q.top().second.first;
        int currentY = q.top().second.second;
        int currentCnt = -q.top().first;
        q.pop();

        if(dp[currentY][currentX] < currentCnt)
            continue;

        if(currentX == M-1 && currentY == N-1)
            return currentCnt;

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            int icnt = currentCnt;
            
            if(!check(ix, iy))
                continue;

            if(s[iy][ix] == '1')
                icnt++;

            if(dp[iy][ix] > icnt){
                dp[iy][ix] = icnt;
                q.push({-icnt, {ix, iy}});
            }
        }

    }

    return -1;
}

// 알고스팟
int main(){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            dp[i][j] = INF;
        }
    }

    cout << dijkstra() << "\n";
  
    return 0;
}