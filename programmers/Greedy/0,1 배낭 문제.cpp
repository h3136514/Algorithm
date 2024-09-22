#include <vector>
#include <algorithm>

using namespace std;
int dp[1001][10001];    // dp[i][j]: i: 아이템 고려한 수(순서대로)  j: 최대 수용 무게

// 그리디 알고리즘 구현 X(최적의 해 보장 못함) => dp 구현
// items: [무게, 가치] 원소(짐)들, weight_limit : 배낭의 수용 무게 가 주어질 때 가방의 무게를 초과하지 않으면서 가방에 들어 있는 짐의 가치가 최대가 되도록 하는 총 가치의 합(짐을 쪼갤 수 없다.) 
double solution(vector<vector<double>> items, int weight_limit) {
    int n = items.size();   // 전체 원소 수

    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= weight_limit; w++) {
            int weight = items[i-1][0];   // 무게
            int value = items[i-1][1];    // 가치
            
            if(weight <= w) //(i-1)번째 짐을 추가할 수 있는 경우
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight] + value);
            else    // (i-1)번째 짐을 추가하지 못하는 경우(이전 짐들을 통한 최대 가치)
                dp[i][w] = dp[i-1][w];
        }
    }
    // 짐 모두를 고려하고 최대 무게를 만족하는 최대가치 반환   
    return dp[n][weight_limit];
}

// 테스트 코드 
#include <iostream>

int main()
{
    cout << solution({{10, 60}, {20, 100}, {30, 120}}, 50) << endl; //출력값 : 220
  
    return 0;
}