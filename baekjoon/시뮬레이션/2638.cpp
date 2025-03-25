#include <iostream>
#include <queue>

using namespace std;
int N, M, CNT, visitied[101][101], board[101][101], cheese[101][101];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

// 범위 확인
bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N;
}

// 초기화
void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cheese[i][j] = 0;
            visitied[i][j] = 0;
        }
    }

    while (!q.empty()){
        q.pop();
    }
    
}

// 치즈 유무 && 녹은 치즈 갱신
bool checkCheese(){
    bool checkC = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(cheese[i][j] >= 2){
                board[i][j] = 0;
            }

            if(board[i][j])
                checkC = true;
        }
    }

    return checkC;
}

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
                if(board[iy][ix]){  // 치즈가 닿으면 +1
                    cheese[iy][ix]++;
                    continue;
                }

                visitied[iy][ix] = 1;
                q.push({ix, iy});
            }
        }
    }

}



int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    while(true){
        if(!checkCheese())
            break;
        
        init();
        CNT++;
        bfs();
    }

    cout << CNT << "\n";

    return 0;
}