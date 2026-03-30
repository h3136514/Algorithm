#include <iostream>
#include <vector>

using namespace std;
int N, M, num, cnt, visitied[100001];
vector<int> V[100001];

void dfs(int start){
    visitied[start] = 1;
    cnt++;

    for(int i = 0; i < V[start].size(); i++){
        if(!visitied[V[start][i]]){
            dfs(V[start][i]);
        }
    }
}

// 점프 점프
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num;
        int r = i - num;
        int l = i + num;
    
        if(r > 0)
            V[i].push_back(r);
        if(l <= N)
            V[i].push_back(l);
    }
    cin >> M;
    dfs(M);

    cout << cnt << "\n";

    return 0;
}