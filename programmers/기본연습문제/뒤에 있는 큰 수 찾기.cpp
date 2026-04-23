// https://school.programmers.co.kr/learn/courses/30/lessons/154539
#include <string>
#include <vector>
#include <queue>

using namespace std;
int N;
vector<int> answer;
priority_queue<pair<int, int>> q;

vector<int> solution(vector<int> numbers) {
    N = numbers.size();
    answer.resize(N);
    
    q.push({-numbers[0], 0});
    for(int i = 1; i < N; i++){
        int num = numbers[i];
    
        while(!q.empty()){
            int inum = -q.top().first;
            int idx = q.top().second;
            
            if(inum < num){
                q.pop();
                answer[idx] = num; 
                continue;
            }
            
            break;
        }
        q.push({-num, i});
    }
    
    while(!q.empty()){
        int idx = q.top().second;
        answer[idx] = -1;
        q.pop();
    }
    
    
    return answer;
}