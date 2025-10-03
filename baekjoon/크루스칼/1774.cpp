#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;
int N, M, v1, v2, parent[1001], visitied[1001];
double sum;
vector<pair<int, int>> V;
priority_queue<pair<double, pair<int, int>>> q;

int find(int x){
    if(x == parent[x])
        return x;
    
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b){
    int nodeA = find(a);
    int nodeB = find(b);

    if(nodeA == nodeB)
        return;

    parent[nodeB] = nodeA;
}

// 거리 계산
double calDist(int a, int b){
    double xDist = pow(V[a].first - V[b].first, 2);
    double yDist = pow(V[a].second - V[b].second, 2);

    return sqrt(xDist + yDist);
}

// 우주신과의 교감
int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;
    V.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin >> V[i].first >> V[i].second;
        parent[i] = i;
    }

    for(int i = 0; i < M; i++){
        cin >> v1 >> v2;

        if(v1 == v2)   // 싸이클 방지
            continue;

        union_set(v1, v2);
    }

    // 모든 신 거리계산
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j)
                continue;
            
            double dist = calDist(i, j);
            q.push({-dist, {i, j}});
        }
    }

    while(!q.empty()){
        double iDist = -q.top().first;
        int ia = q.top().second.first;
        int ib = q.top().second.second;
        q.pop();

        if(find(ia) == find(ib))
            continue;
        
        union_set(ia, ib);
        sum += iDist;
    }

    cout << fixed;
    cout.precision(2);

    cout << sum  << "\n";

    return 0;
}