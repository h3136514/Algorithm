#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
int T, N, K, M, a, b, CNT = 1;
unordered_map<int, int> visited;
vector<int> V[1000001];
vector<pair<int, int>> m;
queue<int> q;

// 초기화
void init(){
    for(int i = 0; i < N; i++)
        V[i].clear();

    visited.clear();
    m.clear();
    CNT = 1;
}

// bfs 탐색
void bfs(int start, int cnt){
    q.push(start);
    visited[start] = cnt;

    while(!q.empty()){
        int currentV = q.front();
        q.pop();

        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];
            if(visited.find(iv) == visited.end()){
                visited[iv] = cnt;
                q.push(iv);
            }
        }
    }
}

// 소셜 네트워킹 어플리케이션
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> N;
        cin >> K;
        for(int j = 0; j < K; j++){
            cin >> a >> b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        cin >> M;
        for(int j = 0; j < M; j++){
            cin >> a >> b;
            m.push_back({a, b});
        }

        for(int j = 0; j < N; j++){
            if(visited.find(j) == visited.end()){
                bfs(j, CNT++);
            }
        }

        cout << "Scenario " << i << ":\n";
        for(int j = 0; j < M; j++){
            a = m[j].first;
            b = m[j].second;

            int result = (visited[a] != visited[b]) ? 0 : 1;
            cout << result << "\n";
        }
        cout <<"\n";

        init();
    }

    return 0;
}
