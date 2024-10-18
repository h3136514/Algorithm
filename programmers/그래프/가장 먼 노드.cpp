#include <string>
#include <vector>
#include <queue>

#define MAX 50001
using namespace std;
int N, maxValue, CNT, dp[20001], visitied[20001];
queue<pair<int, int>> q;
vector<int> V[20001];

void init(){
    for(int i = 1; i <= N; i++){
        dp[i] = MAX;
    }
}

void bfs(){
    visitied[1] = 1;
    q.push({0, 1});
    
    while(!q.empty()){
        int currentV = q.front().second;
        int currentCNT = q.front().first;
        q.pop();
        
        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];
            if(!visitied[iv]){
                visitied[iv] = 1;
                dp[iv] = min(dp[iv], currentCNT+1);
                maxValue = max(maxValue, dp[iv]);
                q.push({currentCNT+1, iv});
            }
        }
    }
}
// n개의 노드가 있는 그래프가 있습니다. 1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지 반환
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    N = n;
    
    for(vector<int> v : edge){
        V[v[0]].push_back(v[1]);
        V[v[1]].push_back(v[0]);
    }
    init();
    
    bfs();
    for(int i = 1; i <= N; i++){
        if(dp[i] == maxValue)
            answer++;
    }
    
    
    return answer;
}