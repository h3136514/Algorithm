#include <string>
#include <vector>
#include <queue>

using namespace std;
int dist[50001];
bool top[50001];
vector<pair<int, int>> V[50001];
vector<int> answer(2);
priority_queue<pair<int, int>> q;

void disktra(){
    while(!q.empty()){
        int currentV = q.top().second;
        int currentCost = q.top().first;
        q.pop();
        
        if(answer[0] != -1 && answer[1] < currentCost)
            continue;
        
        if(top[currentV]){
            if(answer[0] == -1 || answer[1] > currentCost){
                answer[0] = currentV;
                answer[1] = currentCost;
            }else if(answer[1] == currentCost && answer[0] > currentV){ // 산봉우리의 번호가 가장 낮은 등산코스
                answer[0] = currentV;
            }
            
            continue;
        }
        
        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i].first;
            int icost = max(V[currentV][i].second, currentCost);
            
            if(dist[iv] == - 1 || dist[iv] > icost){
                dist[iv] = icost;
                q.push({icost, iv});
            }
        }
    }
    
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    //  dist 배열 -1로 초기화
    for(int i = 1; i <= n; i++){
        dist[i] = -1;
    }
    
    // 시작 점(출입구) 설정
    for(int i = 0; i < gates.size(); i++){
        int v = gates[i];
        
        q.push({0, v});  // 모든 출발지점 큐에 넣기
        dist[v] = 0;
    }
    
    // 산봉우리 표시
    for(int i = 0; i < summits.size(); i++){
        top[summits[i]] = true;
    }
    
    for(vector<int> a : paths){
        V[a[0]].push_back({a[1], a[2]});
        V[a[1]].push_back({a[0], a[2]});
    }
    
    answer[0] = -1, answer[1] = -1;
    
    disktra();
    
    return answer;
}