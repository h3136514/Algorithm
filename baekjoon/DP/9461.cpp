#include <iostream>

using namespace std;
int T, N;
long long dp[101];  // int형 범위 초가(long long)

// 파도반 수열
int main() {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= 100; i++) {
        dp[i] = dp[i-2] + dp[i-3];
    }

    cin >> T;
    while(T--) {
        cin >> N;
        cout << dp[N] << "\n";
    }

    return 0;
}