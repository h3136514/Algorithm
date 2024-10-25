#include <iostream>

using namespace std;
int N, dp[1000001];

// 01타일
int main(){
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }

    cout << dp[N] << "\n";

    return 0;
}