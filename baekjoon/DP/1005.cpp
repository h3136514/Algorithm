#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int T, N, K, X, Y, W, D[1001], DP[1001], indegree[1001];
vector<int> V[1001];
queue<int> q;

void init() {
    for (int i = 1; i <= N; i++) {
        D[i] = 0;
        DP[i] = 0;
        indegree[i] = 0;
        V[i].clear();
    }
}

void bfs(){
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            q.push(i);
            DP[i] = D[i];
        }
    }

    while(!q.empty()){
        int currentV = q.front();
        q.pop();

        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];
            if(indegree[iv] == 0)
                continue;

            DP[iv] = max(DP[iv], DP[currentV] + D[iv]);    
            indegree[iv]--;
            if(indegree[iv] == 0){  // 진입할수 있는 간선이 하나뿐인 건물
                q.push(iv);
            }
        }
    }

}

// ACM Craft
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
        }
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            V[X].push_back(Y);  // 건물 연결상태 (단방향)

            indegree[Y]++;  // Y 건물로 진입할 수 있는 건물수 (진입차수)
        }
        cin >> W;

        bfs();

        cout << DP[W] << "\n";

        init();
   }

    return 0;
}