#include <iostream>

using namespace std;
int N;
int offer_X[2] = {1, 0};
int offer_Y[2] = {0, 1};
long long num[101][101], dp[101][101];

bool check(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

// 점프
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num[i][j];
        }
    }

    dp[0][0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == N-1 && j == N-1)
                continue;

            for(int k = 0; k < 2; k++){
                int x = j + offer_X[k]*num[i][j];
                int y = i + offer_Y[k]*num[i][j];
            
                if(check(x, y)){
                    dp[y][x] += dp[i][j];
                }
            }
        }
    }

    cout << dp[N-1][N-1] << "\n";

    return 0;
}