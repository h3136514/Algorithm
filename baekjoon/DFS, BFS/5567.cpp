// 그래프, BFS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M, CNT, a, b, visitied[501];
vector<int> V[501];
queue<pair<int,int>> q;

void bfs(int start){
    visitied[start] = 1;
    q.push({0, start});

    while(!q.empty()){
        int cnt = q.front().first;
        int currentV = q.front().second;
        q.pop();

        if(cnt >= 2)
            break;
        

        for(int i = 0; i < V[currentV].size(); i++){
            if(visitied[V[currentV][i]])
                continue;
            
            visitied[V[currentV][i]] = 1;
            CNT++;
            q.push({cnt+1, V[currentV][i]});
        }
    }
    
}

// 결혼식
int main(){
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    bfs(1);

    cout << CNT << "\n";

    return 0;
}