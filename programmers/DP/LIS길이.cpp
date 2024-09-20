#include <vector>
#include <algorithm>

using namespace std;
int dp[1001], max_cnt;

// 최장 증가 부분 수열(LIS)의 길이를 계산하는 함수
int solution(vector<int> nums) {
    int n = nums.size();

    // 맨 처음값 셋팅(자기자신)
    dp[0] = 1;
    max_cnt = dp[0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(nums[i] > nums[j])   // nums[i]와 nums[j]를 비교하여, nums[i]가 더 큰 경우에만
                dp[i] = max(dp[i], dp[j] + 1);  // nums[i]를 이용하여 만든 부분 수열의 길이와 nums[j]를 이용하여 만든 부분 수열의 길이 + 1 중 최댓값을 저장

        }
        // 최장 증가 부분 수열의 길이를 반환
        max_cnt = max(max_cnt, dp[i]);
    }
    
    return max_cnt;
}

//테스트 코드 
#include <iostream>

void init() {
    max_cnt = 0;
    for(int i = 0; i <1001; i++)
        dp[i] = 0;
}

int main()
{
    cout << solution({1, 4, 2, 3, 1, 5, 7, 3}) << endl; //출력값 : 5
    init();
    cout << solution({3, 2, 1}) << endl; //출력값 : 1

    return 0;
}