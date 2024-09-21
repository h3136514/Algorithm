#include <vector>
#include <algorithm>

using namespace std;
int max_value, dp[1001][1001];  // 최대 정사각형의 한 변의 길이

int solution(vector<vector<int>> board)
{
    int n = board.size();   // 행의 개수를 변수에 저장합니다.
    int m = board[0].size();    //// 열의 개수를 변수에 저장합니다.
    
    // dp 테이블의 맨 위, 맨 왼쪽 초기화
    for(int i = 0; i < n; i++)
        dp[i][0] = board[i][0];
    for(int j = 0; j < m; j++)
        dp[0][j] = board[0][j];
    
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(board[i][j] == 1) {
                // 현재 위치에서 위, 왼쪽, 대각선 왼쪽 위의 값을 구함
                int left = dp[i][j-1];
                int up = dp[i-1][j];
                int up_left = dp[i-1][j-1];
                
                // 현재 위치의 값을 이전 위치들의 값들 중 가장 작은 값에 1을 더한 값으로 업데이트
                dp[i][j] = min({left, up, up_left}) + 1;
            }
        }
    }
    
    // 보드에서 가장 큰 값(최대 정사각형의 한 변의 길이) 확인
    max_value = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            max_value = max(max_value, dp[i][j]);
    
    // 최대 정사각형 넓이 반환
    return max_value * max_value;
}


// 테스트 코드
#include <iostream>


int main()
{
    cout << solution({{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0}}) << endl; //출력값 : 9
    cout << solution({{0, 0, 1, 1}, {1, 1, 1, 1}}) << endl; //출력값 : 4  
    
    return 0;
}