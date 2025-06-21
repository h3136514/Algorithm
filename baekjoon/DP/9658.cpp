#include <iostream>

using namespace std;
int N, dp[1001];    // dp[i]=1은 i개의 돌이 남았을 때, 상근이의 차례라면 이긴다는 뜻(상근:1  창영:0)

// 돌 게임 4
int main(){
    cin >> N;
    
    dp[2] = dp[4] = dp[5] = 1;
    for(int i = 6; i <= N; i++){
        if(dp[i-1] == 1 && dp[i-3] == 1 && dp[i-4] == 1)
            dp[i] = 0;
        else
            dp[i] = 1;
    }

    if(dp[N] ==1)
        cout << "SK\n";
    else
        cout << "CY\n";

    return 0;
}