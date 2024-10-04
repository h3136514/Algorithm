#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;
int N, a, b, parent[MAX], visitied[MAX];
vector<int> v[MAX];

void dfs(int x) {
    if(visitied[x])
        return;
    
    visitied[x] = 1;
    for(int i = 0; i < v[x].size(); i++) {
        int next = v[x][i];
        if(!visitied[next]) {
            parent[next] = x;
            dfs(next);
        }
    }
}

// 연구소(벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 안전 영역의 최댓값을 구하라)
int main() {

    cin >> N;
    for(int i = 1; i < N; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for(int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}