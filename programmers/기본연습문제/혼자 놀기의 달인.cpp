#include <string>
#include <vector>
#include <queue>

using namespace std;
int visitied[101], top1, top2, answer = 0;
priority_queue<int> q;

int solution(vector<int> cards) {
    for(int i = 0; i < cards.size();i++){
        int target = cards[i] - 1;
        if(visitied[target])
            continue;
        int cnt = 0;
        
        while(!visitied[target]){
            visitied[target] = 1;
            cnt++;
            
            target = cards[target] -1;
        }
        
        q.push(cnt);
    }
    
    if(q.size() == 1){
        answer = 0;
    }else{
        top1 = q.top();
        q.pop();
        top2 = q.top();
    
        answer = top1 * top2;   
    }
    
    return answer;
}