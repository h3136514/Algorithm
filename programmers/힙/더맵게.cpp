#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int> q;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i = 0; i < scoville.size(); i++){
        q.push(-scoville[i]);
    }
    
    while(!q.empty()){
        if(q.size() == 1){
            if(-q.top() < K)
                answer = -1;            
            break;
        }
        int a = -q.top();
        if(a >= K)
            break;
        q.pop();
        int b = -q.top();
        q.pop();
        
        q.push(-(a+b*2));
        
        answer++;
    }
    
    return answer;
}