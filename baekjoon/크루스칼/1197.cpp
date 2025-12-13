#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int V, E, A, B, C, parent[10001], result;
priority_queue<pair<int, pair<int, int>>> q;

int find_x(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find_x(parent[x]);
}

void union_x(int a, int b){
    int rootA = find_x(a);
    int rootB = find_x(b);

    if(rootA != rootB){
        parent[rootB] = rootA;
    }
}

// 최소 스패닝 트리
int main(){
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> A >> B >> C;

        if(A != B)
            q.push({-C, {A, B}});
    }

    for(int i = 1; i <= V; i++){
        parent[i] = i;
    }

    while(!q.empty()){
        int a = q.top().second.first;
        int b = q.top().second.second;
        int value = -q.top().first;
        q.pop();

        if(find_x(a) == find_x(b)){
            continue;
        }

        union_x(a, b);
        result += value;
    }

    cout << result << "\n";

    return 0;
}