// 이분 탐색
#include <iostream>
#include <algorithm>

using namespace std;
long long N, K, num[10001], result, leftNum = 1, rightNum = 0, midNum;

// 랜선 자르기
int main(){
    cin >> K >> N;
    for(int i = 1; i <= K; i++){
        cin >> num[i];
        rightNum = max(rightNum, num[i]);   // 제일 큰 값을 맨끝
    }

    // 이분 탐색 실시
    while(leftNum <= rightNum){
        midNum = (leftNum + rightNum)/2;

        int cnt = 0;
        for(int i = 1; i <= K; i++)
            cnt += num[i] / midNum;
        
        if(cnt >= N){
            leftNum = midNum + 1; // leftNum을 움직여 길이가 더 긴 경우는 가능한지 검사
            result = max(result, midNum);
        }else{
            rightNum = midNum - 1;  // rightNum 움직여 길이가 더 짧은 경우는 가능한지 검사   
        }
    }
    
    cout << result << "\n";

    return 0;
}