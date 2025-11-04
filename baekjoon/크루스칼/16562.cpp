#include <iostream>
#include <queue>

using namespace std;
int N, M, K, a, v, w, sum, parent[10001];
bool check = true;
priority_queue<pair<int, int>> q;

int find_s(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find_s(parent[x]);
}

void union_s(int a, int b){
    int rootA = find_s(a);
    int rootB = find_s(b);

    if(rootA != rootB){
        parent[rootB] = rootA;
    }
}

// 친구비
int main(){
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++){
        cin >> a;
        q.push({-a, i});
    }

    for(int i = 1; i <= N; i++){
        parent[i] = i;
    }
    for(int i = 0; i < M; i++){
        cin >> v >> w;

        if(find_s(v) == find_s(w))
            continue;
        if(v < w)
            union_s(v, w);
        else
            union_s(w, v);
    }

    while(!q.empty()){
        int currentCost = -q.top().first;
        int currentV = q.top().second;
        q.pop();

        if(0 != find_s(currentV)){
            sum += currentCost;

            if(sum > K){
                check = false;
                break;
            }
            union_s(0, currentV);
        }
    }
    if(check){
        for(int i = 1; i <= N; i++){
            if(find_s(i) != 0){
                check = false;
                break;
            }
        }
    }
    

    if(!check)
        cout << "Oh no\n";
    else
        cout << sum << "\n";

    return 0;
}