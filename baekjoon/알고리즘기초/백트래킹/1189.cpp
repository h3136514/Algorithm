#include <iostream>

using namespace std;
int N, R, C, K, CNT, visitied[6][6];
int offer_X[4] = {0, 1, 0, -1};
int offer_Y[4] = {1, 0, -1, 0};
char board[6][6];

bool check(int x, int y){
    return x >= 0 && x < C && y >= 0 && y < R;
}

void backtrack(int x, int y, int cnt){
    if(cnt == K){
        if(x == C-1 && y == 0){
            CNT++;
        }

        return;
    }

    for(int i = 0; i < 4; i++){
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];

        if(check(ix, iy) && board[iy][ix] != 'T' && !visitied[iy][ix]){
            visitied[iy][ix] = 1;
            backtrack(ix, iy, cnt+1);
            visitied[iy][ix] = 0;
        }
    }

}

// 컴백홈
int main(){
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> board[i][j];
        }
    }

    visitied[R-1][0] = 1;
    backtrack(0, R-1, 1);

    cout << CNT << "\n";

    return 0;
}