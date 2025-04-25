// 누적합
#include <iostream>

using namespace std;
int N, M, K, a, b, c, d, num[301][301], dp[301][301];

// 2차원 배열의 합
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> num[i][j];
        }
    }
    // 맨 끝부분 계산
    for(int i = 1; i <= N; i++){
        dp[i][1] = dp[i-1][1] + num[i][1];
    }
    for(int i = 1; i <= M; i++){
        dp[1][i] = dp[1][i-1] + num[1][i];
    }

    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= M; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num[i][j];
        }
    }

    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> a >> b >> c >> d;
        int sum = dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1];    // (a,b) ~ (c,d) 구간합

        cout << sum << "\n";
    }

    return 0;
}