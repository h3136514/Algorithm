#include <iostream>

using namespace std;
int n, dp[1001];

// 2×n 타일링 2
int main() {
    cin >> n;

    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
    }

    cout << dp[n] << "\n";

    return 0;
}