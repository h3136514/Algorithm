#include <iostream>
#include <algorithm>

using namespace std;
int T, N, sum, num[100001][2], dp[100001][2];

// 스티커
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= N; j++){
                cin >> num[j][i];
            }
        }
        dp[1][0] = num[1][0];
        dp[1][1] = num[1][1];
        if(N == 1){
            sum = max(dp[1][0], dp[1][1]);
            cout << sum << "\n";
            continue;
        }

        dp[2][0] = dp[1][1] + num[2][0];
        dp[2][1] = dp[1][0] + num[2][1];
        for(int i = 3; i <= N; i++){
            dp[i][0] = max({dp[i-2][0], dp[i-1][1], dp[i-2][1]}) + num[i][0];
            dp[i][1] = max({dp[i-2][1], dp[i-1][0], dp[i-2][0]}) + num[i][1];
        }

        sum = max(dp[N][0], dp[N][1]);

        cout << sum << "\n";
    }

    return 0;
}