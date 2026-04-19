// https://school.programmers.co.kr/learn/courses/30/lessons/181188#
#include <string>
#include <vector>
#include <queue>

using namespace std;
int answer = 0;
priority_queue<pair<int, int>> q;

int solution(vector<vector<int>> targets) {
    for(auto a : targets){
        q.push({-a[0], - a[1]});
    }
    
    int ago=-1, e = 0;
    while(!q.empty()){
        int is = -q.top().first;
        int ie = -q.top().second;
        q.pop();
        
        if(e == 0){ // 맨 처음
            e = ie;
            ago = is;
            continue;
        }
        
        if(is == ago || is < e){
            e = min(e, ie); // 범위 갱신(제일작은 범위로)
            continue;   
        }else{
            answer++;   // 요격
            e = ie;
            ago = is;
        }
    }
    answer++; // 마지막 요격
    
    return answer;
}