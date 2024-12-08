#include <iostream>
#include <vector>

using namespace std;
int N, num, v, value, maxLen, maxNode, visitied[100001];
vector<pair<int, int>> V[100001];

// 방문, 길이 초기화
void init(){
    for(int i = 1; i <= N; i++)
        visitied[i] = 0;
    
    maxLen = 0;
}

void dfs(int node, int dist){
    visitied[node] = 1;
    // maxLen 갱신
    if(dist > maxLen){
        maxLen = dist;
        maxNode = node;
    }

    // 현재 정점에서 연결 된 방문 안된 정점들로 dfs 수행
    for(int i = 0; i < V[node].size(); i++){
        int iv = V[node][i].first;
        int idist = V[node][i].second;

        if(!visitied[iv]){
            visitied[iv] = 1;
            dfs(iv, dist + idist);
        }
    }
}

// 트리의 지름
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> num;
        while(true){
            cin >> v;
            if(v == -1)
                break;
            
            cin >> value;
            V[num].push_back({v, value});
        }
    }

    // 임의의 정점 1에서 가장 거리가 먼 정점 찾기
    dfs(1, 0);

    init();
    // 1과 가장 먼 정점에서 다시 dfs 수행하여 트리의 지름 찾기
    dfs(maxNode, 0);

    cout << maxLen << "\n";

    return 0;
}