#include <string>
#include <vector>

using namespace std;
int answer = 0;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; 

    for (int coin : money) {
        for (int i = coin; i <= n; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    answer=dp[n]%1000000007;
    
    return answer;
}