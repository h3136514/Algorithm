#include <string>

using namespace std;
int dp[60001];  // dp[i]는 가로 길이가 i일 때 바닥을 채우는 방법의 수

int solution(int n) {
    dp[1] = 1;  // 바닥의 가로 길이가 1인 경우, 바닥을 채우는 방법의 수는 1
    dp[2] = 2;  // 바닥의 가로 길이가 2인 경우, 바닥을 채우는 방법의 수는 2
    
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    
    return dp[n];
}

// 테스트 코드
#include <iostream>


int main()
{
    cout << solution(4) << endl; //출력값 : 5
  
    return 0;
}