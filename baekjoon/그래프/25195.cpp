// https://www.acmicpc.net/problem/25195
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, S, u, v, num[100001];
vector<int> V[100001];
bool check = false;
queue<int> q;

// Yes or yes
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        V[u].push_back(v);
    }
    cin >> S;
    for(int i = 0; i < S; i++){
        cin >> u;
        num[u] = 1;
    }

    q.push(1);

    while(!q.empty()){
        int currentV = q.front();
        q.pop();

        if(num[currentV]){
            check = true;
            continue;
        }

        if(V[currentV].size() == 0){
            check = false;
            break;
        }

        for(int i = 0; i < V[currentV].size(); i++){
            q.push(V[currentV][i]);
        }
    }

    if(check)
        cout << "Yes\n";
    else
        cout << "yes\n";

    return 0;
}
