#include <iostream>
#include <vector>

#define INF 987654321
using namespace std;
int N, K, dp[10001];
vector<int> V;

// 동전 2
int main(){
    cin >> N >> K;

    V.resize(N);
    for(int i = 0; i < N; i++){
        cin >> V[i];
    }

    // 값 초기화
    for(int i = 1; i <= K; i++){
        dp[i] = INF;
    }

    for(int i = 0; i < N; i++){
        for(int j = V[i]; j <= K; j++){
            dp[j] = min(dp[j], dp[j - V[i]] + 1);
        }
    }

    if(dp[K] == INF)
        dp[K] = -1;

    cout << dp[K] << "\n";

    return 0;
}