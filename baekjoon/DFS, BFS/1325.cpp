#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M, a, b, visitied[10001], num[10001], maxLen = 0;
vector<int> V[10001];
queue<int> q;

void init(){
    for(int i = 1; i <= N; i++){
        visitied[i] = 0;
    }
}

void bfs(int startV){
    int cnt = 0;
    q.push(startV);
    visitied[startV] = 1;

    while(!q.empty()){
        int currentV = q.front();
        q.pop();

        for(int i = 0; i < V[currentV].size(); i++){
            int iv = V[currentV][i];

            if(!visitied[iv]){
                visitied[iv] = 1;
                cnt++;
                q.push(iv);
            }
        }

    }

    num[startV] = cnt;
    maxLen = max(maxLen, num[startV]);
}

// 효율적인 해킹
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        V[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        bfs(i);

        init();
    }

    for(int i = 1; i <= N; i++){
        if(maxLen == num[i])
            cout << i << " ";
    }
    cout << "\n";

    return 0;
}