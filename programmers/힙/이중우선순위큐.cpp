#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <queue>

using namespace std;
priority_queue<pair<int, int>> maxq, minq;  // 최댓값, 최솟값 우선순위 큐
unordered_map<int, bool> m; // 인덱스, 삭제유무 저장
int CNT = 0;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(int i = 0; i < operations.size(); i++){
        
        if(operations[i][0] == 'I'){
            stringstream ss(operations[i]);
            string op, str;
            ss >> op >> str;
            int num = stoi(str);
            
            CNT++;
            m[i] = true;
            maxq.push({num, i});
            minq.push({-num, i});
        }else{
            if(CNT <= 0){
                while(!maxq.empty())
                    maxq.pop();
                while(!minq.empty())
                    minq.pop();
              
                continue;
            }
        }
        
        if(operations[i] == "D 1"){
             while(!m[maxq.top().second])
                 maxq.pop();
            
            m[maxq.top().second] = false;
            maxq.pop();
            CNT--;
        }else if(operations[i] == "D -1"){
            while(!m[minq.top().second])
                minq.pop();
            
            m[minq.top().second] = false;
            minq.pop();
            CNT--;
        }
    }
    
    if(CNT == 0){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        while(!m[maxq.top().second])
                 maxq.pop();
        while(!m[minq.top().second])
                minq.pop();
        
        answer.push_back(maxq.top().first);
        answer.push_back(-minq.top().first);
    }
    
    return answer;
}