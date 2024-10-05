// 트리 + DFS
#include <iostream>
#include <vector>

using namespace std;
int N, num, root, target, CNT, visitied[51];
vector<int> V[51];

// dfs(리프노드 탐색)
void dfs(int x) {
    if(visitied[x])
        return;
    visitied[x] = 1;

    if(V[x].size() < 1 || (V[x].size() == 1 && V[x][0] == target)){ // 자식이 없거나 유일한 자식이 지워진 노드일 때
        CNT++;
        return;
    }

    for(int i = 0; i < V[x].size(); i++) {
        int xi = V[x][i];
        if(!visitied[xi] && xi != target){
            dfs(xi);
        }
    }
}

// 트리 (노드 하나를 지었을 때, 남은 트리에서 리프 노드의 개수 반환)
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num;
        if(num == -1){
            root = i;
            continue;
        }

        V[num].push_back(i);
    }
    cin >> target;

    if(target == root)  //루트 노드를 지웠으므로
        CNT = 0;
    else
        dfs(root);

    cout << CNT << "\n";

    return 0;
}