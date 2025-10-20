#include <iostream>
#include <cmath>

#define INF 5000000001
using namespace std;
int N;
long long A[5001], dp[5001];

// 징검다리 건너기 (large)
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        dp[i] = INF;
    }
    
    dp[1] = 0;
    for(int i = 2; i <= N; i++){
        for(int j = 1; j < i; j++){
            long long k = max(dp[j], (i-j)*(1+abs(A[j] -A[i])));
            dp[i] = min(dp[i], k);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}