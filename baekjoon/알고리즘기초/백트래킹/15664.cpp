#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int N, M;
vector<int> v;
set<vector<int>> s;

void backtrack(int idx, int ago, vector<int> tmp){
    if(tmp.size() == M){
        s.insert(tmp);  // 중복 조합 제거

        return;
    }

    for(int i = idx; i < N; i++){
        if(ago <= v[i]){
            tmp.push_back(v[i]);
            backtrack(i + 1, v[i], tmp);
            tmp.pop_back();
        }
    }
}

// N과 M (10)
int main(){
    cin >> N >> M;
    v.resize(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    
    backtrack(0, 0, {});

    for(vector<int> a : s){
        for(int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}