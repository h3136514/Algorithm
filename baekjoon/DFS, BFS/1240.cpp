#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, a, b, v;
bool visitied[1001];
vector<pair<int,int>> V[1001];
queue<pair<int, int>> q;

void init(){
    for(int i = 1; i <= N; i++)
        visitied[i] = false;

    while(!q.empty())
        q.pop();
}

int bfs(){
    q.push({a, 0});
    visitied[a] = true;

    while(!q.empty()){
        int currentV = q.front().first;
        int currentDist = q.front().second;
        q.pop();

        if(currentV == b)
            return currentDist ;

        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i].first;
            int icnt = currentDist + V[currentV][i].second;

            if(!visitied[iv]){
                visitied[iv] = true;
                q.push({iv, icnt});
            }
        }
    }

    return -1;
}

// 노드사이의 거리
int main(){
    cin >> N >> M;
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b >> v;
        V[a].push_back({b, v});
        V[b].push_back({a, v});
    }

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        cout << bfs() << "\n";

        init();
    }

    return 0;
}