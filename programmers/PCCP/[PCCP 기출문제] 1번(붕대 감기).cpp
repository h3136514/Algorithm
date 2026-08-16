#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<pair<int,int>> q;
int T = 0, answer, successCnt = 0;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int tie = bandage[0], sH = bandage[1], aH = bandage[2];
    answer = health;
    
    for(int i = 0; i < attacks.size(); i++){
        q.push({-attacks[i][0], attacks[i][1]});
    }
    
    while(true){
        if(q.empty())
            break;
        T++;
        if(T == -q.top().first){
            int attack = q.top().second;
            q.pop();
            successCnt = 0;
            answer -= attack;
            if(answer <= 0){
                answer = -1;
                break;
            }
            
        }else{
            successCnt++;
            if(successCnt == tie){
                successCnt = 0;
                answer += aH;
            }
            answer += sH;
            
            if(answer > health)
                answer = health;
        }
        
    }
    
    return answer;
}