#include <iostream>

using namespace std;
int N, dp[100001];

// 제곱수의 합
int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        dp[i] = i;

        for(int j = 1; j*j <= i; j++){
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}