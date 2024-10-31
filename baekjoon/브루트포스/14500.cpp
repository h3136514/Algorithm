#include <iostream>

using namespace std;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
int N, M, num[501][501], visitied[501][501], maxSum;

bool check(int x, int y){
    return x > 0 && x <= M && y > 0 && y <= N;
}

// 보라색 'ㅗ'모양 빼고(중간에 튀어나왔으므로 탐색불가) 다 탐색
void dfs(int x, int y, int cnt, int sum){
    if(cnt == 4){
        maxSum = max(maxSum, sum);
        
        return;
    }

    for(int i = 0; i < 4; i++){
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];
        if(check(ix, iy) && !visitied[iy][ix]){
            visitied[iy][ix] = 1;
            dfs(ix, iy, cnt + 1, sum + num[iy][ix]);
            visitied[iy][ix] = 0;
        }
    }
}

// 보라색 'ㅗ'모양 확인
void pupplyPosition(int x, int y){
    int sum;
    // 위 모양
    if(check(x-1, y) && check(x+1, y) && check(x, y+1)){
        sum = num[y][x] + num[y][x-1] + num[y][x+1] + num[y+1][x];
        maxSum = max(maxSum, sum);
    }
    // 아래 모양
    if(check(x-1, y) && check(x+1, y) && check(x, y-1)){
        sum = num[y][x] + num[y][x-1] + num[y][x+1] + num[y-1][x];
        maxSum = max(maxSum, sum);
    }
    // 오른쪽 모양
    if(check(x-1, y) && check(x, y+1) && check(x, y-1)){
        sum = num[y][x] + num[y][x-1] + num[y+1][x] + num[y-1][x];
        maxSum = max(maxSum, sum);
    }
    // 왼쪽 모양
    if(check(x+1, y) && check(x, y+1) && check(x, y-1)){
        sum = num[y][x] + num[y][x+1] + num[y+1][x] + num[y-1][x];
        maxSum = max(maxSum, sum);
    }  

}

// 테트로미노
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++)
            cin >> num[i][j];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            visitied[i][j] = 1;
            dfs(j, i, 1, num[i][j]);
            visitied[i][j] = 0; 

            pupplyPosition(j, i);
        }
    }

    cout << maxSum << "\n";

    return 0;
}