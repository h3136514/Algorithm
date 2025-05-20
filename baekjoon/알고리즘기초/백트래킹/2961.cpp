#include <iostream>
#include <vector>
#include <cmath>

#define IMF 1000000001
using namespace std;
int N, a, b, differ = IMF;
vector<pair<int, int>> v;

void dfs(int maxCnt, int cnt, int idx, int a, int b){
    if(maxCnt == cnt){
        differ = min(differ, abs(a-b));

        return;
    }

    for(int i = idx; i < N; i++){
        dfs(maxCnt, cnt+1, i+1, a*v[i].first, b+v[i].second);
    }
}

// 도영이가 만든 맛있는 음식
int main(){
    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }

    // 재료 갯수별 모든 조합 탐색
    for(int i = 1; i <= N; i++){
        dfs(i, 0, 0, 1, b);
    }

    cout << differ << "\n";

    return 0;
}