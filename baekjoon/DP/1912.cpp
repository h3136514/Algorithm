#include <iostream>
#include <algorithm>

using namespace std;
int N, num[100001], dp[100001], result;

// 연속합(연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합)
int main() {
    cin >> N;
    for(int i= 0; i < N; i++)
        cin >> num[i];
    //초기값
    dp[0]= num[0];
    result = dp[0];
    for(int i = 1; i < N; i++) {
        dp[i] = max(num[i], dp[i-1] + num[i]);  //i번까지의 연속합의 최대값 : [i-1번까지의 최대값 + i번 값] or [i번 값] 둘 중 큰 값
        result = max(result, dp[i]);
    }

    cout << result << "\n";

    return 0;
}