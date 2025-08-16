#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;
const int ROW_SET = 1500;
const int COL_SET = 1500;
int N, M, K, CNT, num[3100][3100];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
string st[50];
queue<pair<int, pair<int, int>>> q;

void bfs(){
    while(!q.empty()){
        int currentCNT = q.front().first;
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        q.pop();

        if(currentCNT >= K)
            continue;

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            int icnt = currentCNT + 1;
            
            if(!num[iy][ix]&& icnt <= K){
                num[iy][ix] = 1;
                q.push({icnt, {ix, iy}});
                CNT++;
            }
        }
    }

}

// 그리드 게임
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> st[i];
    }
    cin >> K;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(st[i][j] =='o'){
                num[i+ROW_SET][j+COL_SET] = 1;
                CNT++;
                q.push({0, {j+COL_SET, i+ROW_SET}});
            }

        }
    }

    bfs();

    cout << CNT << "\n";

    return 0;
}