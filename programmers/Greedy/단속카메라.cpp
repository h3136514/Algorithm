//https://school.programmers.co.kr/learn/courses/30/lessons/42884
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 1, maxStart = 0, maxExit = 0;
int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    
    maxStart = routes[0][0];
    maxExit = routes[0][1];
    
    for(int i = 1; i < routes.size(); i++){
        if(maxExit < routes[i][0]){ // 공통 구간에서 벗어남
            answer++;
            maxStart = routes[i][0];
            maxExit = routes[i][1];
            continue;
        }
        
        // 공통 구간 갱신(더 적은 범위로)
        maxStart = routes[i][0];
        if(maxExit > routes[i][1]){
            maxExit =routes[i][1];
        }
    }
    
    return answer;
}