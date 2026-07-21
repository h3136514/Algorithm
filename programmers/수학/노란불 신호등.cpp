// https://school.programmers.co.kr/learn/courses/30/lessons/468371
#include <string>
#include <vector>

using namespace std;
int num[5], cnt[5], maxNum = 1, GYRSize, answer = -1;

// 유클리드호제법 (최대 공약수)
long long gcd(long long a, long long b){
    if(!b)
        return a;
    return gcd(b, a%b);
}

// 최소 공배수
long long llm(long long a, long long b){
    return a*b / gcd(a, b);
}

int solution(vector<vector<int>> signals) {
    GYRSize = signals.size(); // 신호등 갯수
    
    for(int i = 0; i < GYRSize; i++){
        int sum = (signals[i][0] + signals[i][1] + signals[i][2]);
        maxNum = llm(maxNum, (long long)sum);   // 모든 신호등 합의 최소 공배수
        cnt[i] = signals[i][0]; // 신호등별 현재 남은 초
    } 
      
    for(int i = 1; i <= maxNum; i++){
        bool check = true;
        for(int j = 0; j < GYRSize; j++){
            if(num[j] != 1){
                check = false;
                break;
            }
        }
        
        if(check){  // 모든 신호등이 노란불(index == 1)일 때
            answer = i;
            break;
        }
        
        for(int j = 0; j < GYRSize; j++){
            cnt[j]--;
            if(cnt[j] == 0){
                num[j] = (num[j] == 2) ? 0 : num[j] + 1;
                cnt[j] = signals[j][num[j]];
            }
        }
    }
    
    return answer;
}