#include <string>

using namespace std;
long long dp[100001];

// 피보나치 수열의 n번째 값을 계산하는 함수
int solution(int n) {
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    
    return dp[n];
}

//테스트 코드
#include <iostream>


int main()
{
  cout << solution(3) << endl; //출력값 : 2
  cout << solution(5) << endl; //출력값 : 5
  
  return 0;
}