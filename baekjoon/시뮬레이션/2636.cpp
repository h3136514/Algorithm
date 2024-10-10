#include <iostream>
#include <queue>

using namespace std;
int N, M, CNT, pastCNT, num[101][101], visitied[101][101], times = 0;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

// 초기화
void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visitied[i][j] = 0;
        }
    }
}

// 범위확인
bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N;
}

// bfs
void bfs(){
    q.push({0, 0});
    visitied[0][0] = 1;

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix]){
                visitied[iy][ix] = 1;
                if(num[iy][ix] == 1){   // 인접한 치즈들을(겉면) 제거
                    CNT--;
                    num[iy][ix] = 0;
                }else
                    q.push({ix, iy});
            }
        }
    }

}

// 치즈
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> num[i][j];
            if(num[i][j] == 1)
                CNT++;
        }
    }

    while(CNT > 0){
        times++;
        pastCNT = CNT;
        bfs();

        init();
    }

    cout << times << "\n";
    cout << pastCNT << "\n";

    return 0;
}