// bfs
// https://www.acmicpc.net/problem/14496
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int a, b, c, d, N, M, visitied[1001], result;
vector<int> V[1001];
queue<pair<int, int>> q;

int bfs(){
    if(a == b){
        return 0;
    }
    visitied[a] = 1;
    q.push({a, 0});

    while(!q.empty()){
        int currentV = q.front().first;
        int currentCnt = q.front().second;
        q.pop();

        if(currentV == b)
            return currentCnt;
        
        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];
            int icnt = currentCnt + 1;

            if(!visitied[iv]){
                visitied[iv] = 1;
                q.push({iv, icnt});
            }
        }
    }

    return -1;
}

// 그대, 그머가 되어
int main(){
    cin >> a >> b;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> c >> d;
        if(c != d){
            V[c].push_back(d);
            V[d].push_back(c);
        }
    }

    result = bfs();

    cout << result << "\n";

    return 0;
}