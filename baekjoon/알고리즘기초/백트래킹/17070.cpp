#include <iostream>

using namespace std;
int N, board[17][17], CNT;
int offer_X[3] = {1, 0, 1}; // 세로, 가로, 대각선 이동 좌표
int offer_Y[3] = {0, 1, 1};

bool check(int x, int y, int dir){
    if(x <= 0 || x > N || y <= 0 || y > N || board[y][x] == 1)
        return false;

    if(dir == 0){   // 가로 방향
       int ix = x + offer_X[dir];
       int iy = y + offer_Y[dir];

        if(ix <= 0 || ix > N || iy <= 0 || iy > N || board[iy][ix] == 1)
            return false;
    }else if(dir == 1){ // 세로 방향
        int ix = x + offer_X[dir];
        int iy = y + offer_Y[dir];

        if(ix <= 0 || ix > N || iy <= 0 || iy > N || board[iy][ix] == 1)
            return false;
    }else{  // 대각선 방향
        for(int i = 0; i < 3; i++){
            int ix = x + offer_X[i];
            int iy = y + offer_Y[i];

            if(ix <= 0 || ix > N || iy <= 0 || iy > N || board[iy][ix] == 1)
                return false;
        }
    }

    return true;
}

void backtrack(int x, int y, int dir){
    if(x == N && y == N){
        CNT++;
        return;
    }

    if(dir == 0){   // 가로 방향(가로, 대각선)
        if(check(x, y, dir))
            backtrack(x+1, y, dir);

        if(check(x, y, 2))
            backtrack(x+1, y+1, 2);

    }else if(dir == 1){ // 세로 방향(세로, 대각선)
        if(check(x, y, dir))
            backtrack(x, y+1, dir);

        if(check(x, y, 2))
            backtrack(x+1, y+1, 2);

    }else{  // 대각선 방향(가로, 세로, 대각선)
        if(check(x, y, 0))
            backtrack(x+1, y, 0);

        if(check(x, y, 1))
            backtrack(x, y+1, 1);

        if(check(x, y, dir))
            backtrack(x+1, y+1, dir);
    }
}

// 파이프 옮기기 1
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
        }
    }

    backtrack(2, 1, 0);

    cout << CNT << "\n";

    return 0;
}