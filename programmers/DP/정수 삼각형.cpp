#include <string>
#include <vector>

using namespace std;
int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    
    // dp 테이블의 맨 아래쪽 라인 초기화
    for(int i = 0; i < n; i++)
        dp[n-1][i] = triangle[n-1][i];
    
     // 아래쪽 라인부터 올라가면서 dp 테이블 채우기
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < triangle[i].size(); j++) {
            dp[i-1][j] = max(dp[i][j], dp[i][j+1]) + triangle[i-1][j];
        }
    }
    
    return dp[0][0];    // 꼭대기에서의 최댓값 반환
}

//테스트 코드
#include <iostream>


int main()
{
  cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl; //출력값 : 30
  
  return 0;
}