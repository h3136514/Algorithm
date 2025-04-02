// DFS
#include <iostream>
#include <vector>

using namespace std;
int N, M, a, b, visitied[2000], CNT, exist;
vector<int> v[2000];

void dfs(int start, int cnt){
    // 이미 방문했거나 존재를 확인했으면
    if(visitied[start] || CNT >= 4)
        return;

    visitied[start] = 1;
    CNT = max(CNT, cnt);

    for(int j = 0; j < v[start].size(); j++){
        if(!visitied[v[start][j]])
            dfs(v[start][j], cnt+1);
    }

    visitied[start] = 0;    // 방문 초기화

}

// ABCDE
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 0; i < N; i++){
        dfs(i, 0);

        if(CNT >= 4)
            break;
    }

    exist = (CNT >= 4) ? 1 : 0;

    cout << exist << "\n";

    return 0;
}