// https://www.acmicpc.net/problem/1520
// dfs, 메모제이션
#include <iostream>

using namespace std;
int N, M, num[501][501], dp[501][501];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};

bool check(int x, int y){
    return x >= 0 && y >= 0 && x < M && y < N; 
}

int dfs(int x, int y){
    if(x == M-1 && y == N - 1)
        return 1;
    if(dp[y][x] != -1)
        return dp[y][x];
    
    dp[y][x] = 0;
    for(int i = 0; i < 4; i++){
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];

        if(check(ix, iy) && num[y][x] > num[iy][ix]){
            dp[y][x] += dfs(ix, iy);
        }
    }
    
    return dp[y][x];
}

// 내리막 길
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> num[i][j];
            dp[i][j] = -1;
        }
    }

    cout << dfs(0, 0) << "\n";

    return 0;
}