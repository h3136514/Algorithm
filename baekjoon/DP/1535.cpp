#include <iostream>

using namespace std;
int N, health[21], happy[21], dp[21][101], maxHappy;

// 안녕
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> health[i];
    }

    for(int i = 1; i <= N; i++){
        cin >> happy[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < 100; j++){

            if(j < health[i]){
                // 체력이 부족해서 i번 사람에게 인사 못하는 경우
                dp[i][j] = dp[i-1][j];
            } else {
                // i번 사람에게 인사할 수 있는 경우
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - health[i]] + happy[i]);
            }

            maxHappy = max(maxHappy, dp[i][j]);
        }
    }

    cout << maxHappy << "\n";

    return 0;
}