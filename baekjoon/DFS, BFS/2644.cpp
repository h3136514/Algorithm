#include <iostream>
#include <queue>
#include <vector>

#define MAX 101
using namespace std;
int N, M, targetA, targetB, x, y, CNT, visitied[MAX];
queue<pair<int,int>> q;
vector<int> V[MAX];

// BFS
int bfs(int start) {
    visitied[start] = 1;
    q.push({start, 0});

    while(!q.empty()) {
        int next = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(next == targetA)
            return cnt;

        for(int i = 0; i < V[next].size(); i++) {
            int iX = V[next][i];
            
            if(!visitied[iX]) {
                visitied[iX] = 1;
                q.push({iX, cnt+1});
            }
        }
    }

    return -1;
}

// 촌수계산
int main() {
    cin >> N;
    cin >> targetA >> targetB;
    cin >> M;

    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        V[x].push_back(y);
        V[y].push_back(x);
    }
    
    CNT = bfs(targetB);

    cout << CNT << "\n";

    return 0;
}