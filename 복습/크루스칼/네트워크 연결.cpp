// 크루스칼 알고리즘
#include <iostream>
#include <queue>

using namespace std;
int N, M, a, b, c, sumCost, parent[1001];
priority_queue<pair<int, pair<int, int>>> q;

// 부모 찾기
int find(int x) {
    if(parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x]);
}

// 부모 합치기
void union_set(int a, int b) {
    int root1 = find(a);
    int root2 = find(b);

    if(root1 != root2)
        parent[root2] = root1; 
}

// 네트워크 연결(백준 1922번)
int main() {
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        q.push({-c, {a, b}});
    }

    // 초기화
    for(int i = 1; i <= N; i++)
        parent[i] = i;

    while (!q.empty()){
        a = q.top().second.first;
        b = q.top().second.second;
        int cost = -q.top().first;
        q.pop();

        if(find(a) == find(b))  // 싸이클 방지
            continue;

        union_set(a, b);
        sumCost += cost;
    }

    cout << sumCost << "\n";
    
    return 0;
}
