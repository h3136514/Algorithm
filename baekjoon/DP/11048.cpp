#include <iostream>
#include <algorithm>

using namespace std;
int N, M, num[1001][1001], dp[1001][1001];

// 이동하기
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> dp[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j] += max({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}); 
        }
    }

    cout << dp[N][M] << "\n";

    return 0;
}