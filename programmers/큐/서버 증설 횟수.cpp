// https://school.programmers.co.kr/learn/courses/30/lessons/389479

#include <string>
#include <vector>
#include <queue>

using namespace std;
int answer = 0, cnt = 1;
priority_queue<int> q;

int solution(vector<int> players, int m, int k) {
    for(int i = 0; i < players.size(); i++){
        // 서버 시간 체크
        while(!q.empty()){
            if(-q.top() == i){
                q.pop();
                cnt--;
                continue;
            }
            break;
        }
        
        // 현재 이용자 수가 cnt(서버수-1) * m명 이상이면 서버 증설
        if(players[i] >= cnt*m){
            int add = (players[i] - cnt*m)/m + 1;
            for(int j = 0; j < add; j++){
                q.push(-(i+k));  
            }
            cnt += add;
            answer += add;
        }
    
    }
    
    return answer;
}