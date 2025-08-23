#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;
int H, W, CNT, dp[101][101], visitied[101][101];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
string s[101];
priority_queue<pair<pair<int, int>, pair<int, int>>> q;
vector<pair<int, int>> C;

bool check(int x, int y){
    return x >= 0 && x < W && y >= 0 && y < H;
}

void dijkstra(int startX, int startY, int d){
    q.push({{0, d},{startX, startY}});
    dp[startY][startX] = 0;
    visitied[startX][startY]++;

    while(!q.empty()){
        int currentCnt = -q.top().first.first;
        int currentdir = q.top().first.second;
        int currentX = q.top().second.first;
        int currentY = q.top().second.second;
        q.pop();

        if(dp[currentY][currentX] < currentCnt)
            continue;

        if(currentX == C[1].first && currentY == C[1].second){
            CNT = min(CNT, currentCnt);
            continue;
        }

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            int icnt = (i != currentdir) ? currentCnt + 1 : currentCnt;

            if(check(ix, iy) && s[iy][ix] != '*' && dp[iy][ix] >= icnt){
                dp[iy][ix] = icnt;
                visitied[iy][ix]++;

                q.push({{-icnt, i},{ix, iy}});
            }
        }
    }
}

// 레이저 통신
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> W >> H;
    for(int i = 0; i < H; i++){
        cin >> s[i];
    }

    CNT = H*W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(s[i][j] == 'C')
                C.push_back({j, i});
            
            dp[i][j] = H*W;
        }
    }

    for(int i = 0; i < 4; i++)
        dijkstra(C[0].first, C[0].second, i);

    cout << CNT << "\n";

    return 0;
}