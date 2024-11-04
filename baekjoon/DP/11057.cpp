#include <iostream>

using namespace std;
int N, sum, dp[1001][10];

// 초기 값
void init(){
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < 10; j++)
            dp[i][j] = 1;
}

// 오르막 수
int main(){
    cin >> N;
    init();

    for(int i = 2; i <= N; i++){
        for(int j = 8; j >= 0; j--){
            dp[i][j] = (dp[i-1][j] + dp[i][j+1]) % 10007;
        }
    }

    for(int j = 0; j < 10; j++)
        sum = (sum + dp[N][j]) % 10007;
    
    cout << sum << "\n";

    return 0;
}