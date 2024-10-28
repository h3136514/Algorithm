#include <iostream>
#include <string>

using namespace std;
int N, M, dp[1002][1002]; 
string str1, str2;

// LCS
int main(){
    cin >> str1;
    cin >> str2;
    N = str1.size();
    M = str2.size();

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(str1[i-1] == str2[j-1])  // 현재 문자열이 같은지
                dp[i][j] =dp[i-1][j-1] + 1; // 이전 i-1번째 문자열 기준으로 본 값에 +1
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // 이전 i-1번째 문자열 또는 현재 전(j-1번째) 문자열 중에 최댓값
        }
    }

    cout << dp[N][M] << "\n";

    return 0;
}