#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, a, num[9], visitied[10001];
vector<int> v;

void dfs(int idx, int cnt){
    if(cnt == M){
        for(int i = 0; i < cnt; i++)
            cout << num[i] << " ";
        cout << "\n";

        return;
    }

    for(int i = idx; i < v.size(); i++){
        num[cnt] = v[i];
        dfs(i, cnt+1);
    }
}

// N과 M (12)
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a;
        if(!visitied[a]){
            visitied[a] = 1;
            v.push_back(a);
        }
    }

    sort(v.begin(), v.end());

    dfs(0, 0);

    return 0;
}