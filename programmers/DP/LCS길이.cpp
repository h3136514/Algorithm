#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp[1001][1001];

// 두 문자열의 LCS 길이를 계산하는 함수
int solution(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();

    for(int i = 1; i <=m; i++) {
        for(int j = 1; j <=n; j++) {
            // 문자가 같으면
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }else { // 문자가 같지 않으면
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}


// 테스트 코드
#include <iostream>

void init() {
    for(int i = 0; i < 1001; i++)
        for(int j = 0; j < 1001; j++)
            dp[i][j] = 0;
}

int main()
{
  cout << solution("ABCBDAB","BDCAB") << endl; //출력값: 4
  init();
  cout << solution("AGGTAB", "GXTXAYB") << endl; //출력값 :4
 
  return 0;
}