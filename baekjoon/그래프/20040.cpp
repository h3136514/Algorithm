#include <iostream>
#include <vector>

using namespace std;
int N, M, result, parent[500001];
vector<pair<int, int>> V;

int find(int a){
    if(a == parent[a])
        return a;
    
    return parent[a] = find(parent[a]);
}

void union_s(int a, int b){
    int rootA = find(a);
    int rootB = find(b);

    if(rootA < rootB)
        parent[rootB] = rootA;
    else
        parent[rootA] = rootB;
}

// 사이클 게임 (사이클 확인)
int main(){
    cin >> N >> M;
    V.resize(M);

    for(int i = 0; i < M; i++){
        cin >> V[i].first >> V[i].second;
    }

    for(int i = 0; i < N; i++)
        parent[i] = i;
    
    for(int i = 0; i < M; i++){
        int a =  V[i].first;
        int b =  V[i].second;

        if(find(a) == find(b)){
            
            result = i + 1;
            break;
        }

        union_s(a, b);
    }

    cout << result << "\n";

    return 0;
}