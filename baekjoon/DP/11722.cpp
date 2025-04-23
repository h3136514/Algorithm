#include <iostream>

using namespace std;
int N, A[1001], dp[1001], maxLen;

// 가장 긴 감소하는 부분 수열
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    dp[1] = 1;  // 자기자신
    maxLen = dp[1];
    for(int i = 2; i <= N; i++){
        dp[i] = 1;
        for(int j = 1; j <= i; j++){
            if(A[j] > A[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
        
        maxLen = max(maxLen, dp[i]);
    }

    cout << maxLen << "\n";


    return 0;
}