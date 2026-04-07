// https://www.acmicpc.net/problem/6118
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M, u, v, visitied[20001], target, dist, cnt = 1;
vector<int> V[20001];
queue<pair<int, int>> q;
priority_queue<pair<int, int>> answer;

void bfs(){
    visitied[1] = 1;
    q.push({1, 0});

    while(!q.empty()){
        int currentV = q.front().first;
        int currentDist = q.front().second;
        q.pop();

        for(int i = 0; i < V[currentV].size(); i++){
            int iv =V[currentV][i];
            int iDist = currentDist + 1;
            
            if(!visitied[iv]){
                q.push({iv, iDist});
                visitied[iv] = 1;

                answer.push({iDist, -iv});
            }
        }
    }
}

// 숨바꼭질
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    bfs();

    dist = answer.top().first;
    target = -answer.top().second;
    answer.pop();
    while(!answer.empty()){
        if(answer.top().first == dist)
            cnt++;
        else
           break;

        answer.pop();
    }

    cout << target << " " << dist << " " << cnt << "\n";

    return 0;
}