#include <iostream>
#include <algorithm>

using namespace std;
int N, num[1001][3], dp[1001][3];

// RGB거리
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++)
            cin >> num[i][j];
    }
    // 초기 값
    dp[0][0] = num[0][0];
    dp[0][1] = num[0][1];
    dp[0][2] = num[0][2];

    for(int i = 1; i < N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + num[i][0];  // 빨강을 선택할 때
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + num[i][1];  // 초록을 선택할 때
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + num[i][2];  // 파랑을 선택할 때
    } 

    int result = min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});

    cout << result << "\n";

    return 0;
}