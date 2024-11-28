#include <iostream>

using namespace std;
int N, sum, num[1001], dp[1001];   //자기를 포함한 가장 큰 증가하는 부분 수열합

// 가장 큰 증가하는 부분 수열
int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    dp[0] = num[0];
    for(int i = 1; i < N; i++){
        dp[i] = num[i];
        for(int j = 0; j <= i; j++){
            if(num[i] > num[j]){
                dp[i] = max(dp[i], dp[j] + num[i]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        sum = max(sum, dp[i]);
    }

    cout << sum << "\n";

    return 0;
}