#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, a, r, visitied[201];
vector<int> road, V[201];
queue<int> q;

void bfs(int startV){
    visitied[startV] = 1;
    q.push(startV);

    while(!q.empty()){
        int currentV = q.front();
        q.pop();

        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];

            if(!visitied[iv]){
                visitied[iv] = 1;
                q.push(iv);
            }
        }
    }

}

// 여행 가자
int main(){
    cin >> N;
    cin >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> a;
            if(a == 1){
                V[i].push_back(j);
            }

        }
    }

    road.resize(M);
    for(int i = 0; i < M; i++){
        cin >> road[i];
    }

    bfs(road[0]);

    for(int i = 0; i < M; i++){
        if(!visitied[road[i]]){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}