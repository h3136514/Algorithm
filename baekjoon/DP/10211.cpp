// 누적합, 부분합
#include <iostream>

#define MAXVALUE 1001
using namespace std;
int T, N, maxNum, num[MAXVALUE], dp[MAXVALUE];

// Maximum Subarray
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 1; i <= N; i++)
            cin >> num[i];
        maxNum = -1001;

        for(int i = 1; i <= N; i++){
            dp[i] = max(num[i] + dp[i-1], num[i]);
            maxNum = max(maxNum, dp[i]);
        }

        cout << maxNum << "\n";
    }

    return 0;
}