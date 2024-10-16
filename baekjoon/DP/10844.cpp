#include <iostream>

using namespace std;
int N, sum, dp[101][101];

// 쉬운 계단 수
int main() {
	cin >> N;
	
    for(int i = 1; i < 10; i++)
        dp[1][i] = 1;

	for(int i = 2; i <= N; i++) {
        for(int j = 0; j < 10; j++){
            if(j == 0)  // 0으로 끝나는 수
                dp[i][j] = dp[i-1][j+1];
            else if(j == 9) // 9로 끝나는 수
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1]) % 1000000000;
            

        }
	}
    // 총합
	for(int i = 0; i < 10; i++){
        sum = (sum + dp[N][i]) % 1000000000;
    }

	cout << sum << "\n";

	return 0;
}