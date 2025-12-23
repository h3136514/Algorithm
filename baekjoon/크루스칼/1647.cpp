// https://www.acmicpc.net/problem/1647
#include <iostream>
#include <queue>

using namespace std;
int N, M, A, B, C, parent[100001], path = 0, result;
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

// 도시 분할 계획
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> C;
        if(A != B)
            q.push({-C, {A, B}});
    }

    for(int i = 1; i <= N; i++)
        parent[i] = i;
    
    while(!q.empty()){
        int c = -q.top().first;
        int a = q.top().second.first;
        int b = q.top().second.second;
        q.pop();

        if(find_x(a) != find_x(b)){
            path = max(path, c);
            result += c;

            union_x(a, b);
        }
    }

    cout << result-path << "\n";

    return 0;
}