#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp1[1000001];   // 첫 번째 집을 터는 경우 최댓값
int dp2[1000001];   // 첫 번째 집을 안 터는 경우 최댓값

int solution(vector<int> money) {
    int n = money.size();
    
    // 첫 번째 집을 터는 경우
    dp1[0] = money[0];
    dp1[1] = money[0];
    for(int i = 2; i < n - 1; i++)
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i]);
    
    // 첫 번째 집을 털지 않는 경우
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i = 2; i < n; i++)
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
    
    // 두 경우 중, 최대값 찾기
    int answer = max(dp1[n-2], dp2[n-1]);
    return answer;
}


// 테스트 코드
#include <iostream>


int main()
{
  cout << solution({1, 2, 3, 1}) << endl; //출력값 : 4
  
  return 0;
}