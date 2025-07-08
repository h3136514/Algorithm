#include <iostream>
#include <queue>

#define MAX 987654321
using namespace std;
int N, CNT = 1, num[126][126], dp[126][126];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
priority_queue<pair<int, pair<int, int>>> q;

bool check(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dijkstra(){
    q.push({-num[0][0], {0, 0}});

    while(!q.empty()){
        int currentV = -q.top().first;
        int currentX = q.top().second.first;
        int currentY = q.top().second.second;
        q.pop();

        if(dp[currentY][currentX] < currentV)
            continue;
        
        dp[currentY][currentX] = currentV;

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && dp[iy][ix] > currentV + num[iy][ix]){
                q.push({-(currentV + num[iy][ix]), {ix, iy}});
            }
        }

    }
}

// 녹색 옷 입은 애가 젤다지? 
int main(){
    while(true){
        cin >> N;
        if(N == 0)
            break;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> num[i][j];
                dp[i][j] = MAX;
            }
        }
        
        dijkstra();

        cout << "Problem " << CNT++ << ": " << dp[N-1][N-1] << "\n";
    }

    return 0;
}