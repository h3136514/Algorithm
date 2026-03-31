#include <iostream>

using namespace std;
int d;
long long dp[8], num[8];

int main(){
	cin >> d;

	dp[0] = 1;
	while (d--){
		num[0] = dp[1] + dp[2];
		num[1] = dp[0] + dp[2] + dp[3];
		num[2] = dp[0] + dp[1] + dp[3] + dp[4];
		num[3] = dp[1] + dp[2] + dp[4] + dp[5];
		num[4] = dp[2] + dp[3] + dp[5] + dp[6];
		num[5] = dp[3] + dp[4] + dp[7];
		num[6] = dp[4] + dp[7];
		num[7] = dp[5] + dp[6];

		for (int i = 0; i < 8; i++)
			dp[i] = num[i] % 1000000007;
	}

	cout << dp[0];
	return 0;
}