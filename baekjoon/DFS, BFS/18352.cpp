// BFS
#include <iostream>
#include <queue>
#include <vector>

#define MAX 1000001
using namespace std;
int N, M, K, X, A, B, visitied[300001], dp[300001];
vector<int> result, V[300001];
queue<pair<int, int>> q;

// 최대거리로 초기화
void init(){
    for(int i = 1; i <= N; i++)
        dp[i] = MAX;
}

// bfs
void bfs(int start){
    dp[start] = 0;
    visitied[start] = 1;
    q.push({0, start});

    while(!q.empty()){
        int currentV = q.front().second;
        int currentCNT = q.front().first;
        q.pop();

        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];

            if(!visitied[iv]){
                visitied[iv] = 1;
                dp[iv] = min(dp[iv], currentCNT+1);
                q.push({currentCNT+1, iv});
            }
        }
    }
}

// 특정 거리의 도시 찾기
int main(){
    cin >> N >> M >> K >> X;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        V[A].push_back(B);
    }

    init();
    bfs(X);

    for(int i = 1; i <= N; i++){
        if(dp[i] == K){
            result.push_back(i);
        }
    }

    if(result.size() == 0)
        cout << -1 << "\n";
    else{
        for(int i = 0; i < result.size(); i++){
            cout << result[i] << "\n";
        }
    }

    return 0;
}