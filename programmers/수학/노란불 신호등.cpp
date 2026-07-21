// https://school.programmers.co.kr/learn/courses/30/lessons/468371
#include <string>
#include <vector>

using namespace std;
int num[5], cnt[5], maxNum = 1, GYRSize, answer = -1;

int solution(vector<vector<int>> signals) {
    GYRSize = signals.size();
    for(int i = 0; i < GYRSize; i++){
        maxNum *= (signals[i][0] + signals[i][1] + signals[i][2]);
        cnt[i] = signals[i][0];
    } 
      
    for(int i = 1; i <= maxNum; i++){
        bool check = true;
        for(int j = 0; j < GYRSize; j++){
            if(num[j] != 1){
                check = false;
                break;
            }
        }
        
        if(check){
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