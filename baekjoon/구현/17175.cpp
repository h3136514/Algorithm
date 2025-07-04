#include <iostream>

using namespace std;
int N, dp[51];

// 피보나치는 지겨웡~
int main(){
    cin >> N;

    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= N; i++)
        dp[i] = (dp[i-2] + dp[i-1] + 1) % 1000000007;

    cout << dp[N] << "\n";

    return 0;
}