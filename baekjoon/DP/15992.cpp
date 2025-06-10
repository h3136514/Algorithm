#include <iostream>

#define MAX 987654321
#define MOD 1000000009

using namespace std;
int T, n, m, dp[1001][1001];

// 1, 2, 3 더하기 7
int main(){
    cin >> T;
    dp[1][1] = dp[2][1] = dp[3][1] = 1; // 1, 2, 3이 각자 1개씩 사용한 경우

    for(int i = 2; i < 1001; i++){  // 갯수
        for(int j = 1; j < 1001; j++){ // 목표 값
            for(int k = 1; k < 4; k++){ // 1, 2, 3
                if(j-k <= 0)
                    continue;
                
                dp[j][i] += dp[j-k][i-1];
                dp[j][i] %= MOD;
            }
        }
    }

    while(T--){
        cin >> n >> m;

        cout << dp[n][m] << "\n";
    }

    return 0;
}