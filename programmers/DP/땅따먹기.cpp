#include <algorithm>
#include <vector>


using namespace std;
int dp[100001][4]; 

int solution(vector<vector<int>> land)
{
    int n = land.size();
    // dp 테이블의 맨 위 행 초기화
    for(int i = 0; i < 4; i++)
        dp[0][i] = land[0][i];
    
    // 각 행마다 이전 행에서의 최대 점수를 더해가며 최대 점수 누적
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 4; j++) {   
            // 이전 행에서 현재 열의 값을 제외한 나머지 열들 중에서 가장 큰 값을 더함
            if(j == 0)
                dp[i][j] = max({dp[i-1][1], dp[i-1][2], dp[i-1][3]}) + land[i][j];
            else if(j == 1)
                dp[i][j] = max({dp[i-1][0], dp[i-1][2], dp[i-1][3]}) + land[i][j];
            else if(j == 2)
                dp[i][j] = max({dp[i-1][0], dp[i-1][1], dp[i-1][3]}) + land[i][j];
            else
                dp[i][j] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]}) + land[i][j];
        }
    }
    
    // 마지막 행에서 얻을 수 있는 최대 점수
    int result = max({dp[n-1][0], dp[n-1][1], dp[n-1][2], dp[n-1][3]});

    return result;
}


// 테스트 코드
#include <iostream>


int main()
{
    cout << solution({{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}}) << endl; //출력값 : 16
  
    return 0;
}