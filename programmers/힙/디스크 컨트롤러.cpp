// https://school.programmers.co.kr/learn/courses/30/lessons/42627#
#include <string>
#include <vector>
#include <queue>

using namespace std;
int N, sum = 0, currentTime = 0, idx = 1, answer = 0;
priority_queue<pair<int, pair<int, int>>> q;
priority_queue<pair<int, pair<int, int>>> process;

int solution(vector<vector<int>> jobs) {
    N = jobs.size(); 
    
    for(int i = 0; i < jobs.size(); i++){
        process.push({-jobs[i][0], {jobs[i][1], i}});   // 요청작업 큐
    }
    
    while(!q.empty() || !process.empty()){
            while(!process.empty()){ // 대기 큐에 작업 넣기
            int istartTime = - process.top().first;
            int itime = process.top().second.first;
            int iIdx = process.top().second.second;
            process.pop();


            if(q.empty() && currentTime < istartTime){ // 대기큐가 비어있고 요청시각이 아직 아니면
                currentTime = istartTime;
            }

            if(istartTime > currentTime){   // 요청시각이 아직 아니면
                process.push({-istartTime, {itime, iIdx}});
                break;
            }

            q.push({-itime, {-istartTime, -iIdx}});
        }
        
        
        if(!q.empty()){ // 대기 큐에 작업이 있으면 처리
            int itime = - q.top().first;
            int istartTime = -q.top().second.first;
            int iIdx = -q.top().second.second;
            q.pop();

            currentTime += itime;
            sum += currentTime - istartTime;
        }
    
    }
    
    answer = sum/N;
    
    return answer;
}