//https://www.acmicpc.net/problem/16987
#include <iostream>
#include <vector>

using namespace std;
int N, CNT;
vector<pair<int, int>> v;

void backtracking(int idx, int cnt, vector<pair<int, int>> egg){
    if(idx == N){
        CNT = max(CNT, cnt);
        return;
    }
    
    int currentS = egg[idx].first;
    int currentW = egg[idx].second;
    if(currentS == 0){
        backtracking(idx+1, cnt, egg);
        return;
    }

    for(int i = 0; i < N; i++){
        int is = egg[i].first;
        int iw = egg[i].second;
        int icnt = cnt;
    
        if(i==idx)
            continue;

        if(is == 0){
            if(i == N-1){
                backtracking(idx+1, cnt, egg);
            }
            continue;
        }

        vector<pair<int, int>> tmp = egg;
        tmp[i].first = (is - currentW < 0) ? 0: is - currentW;
        tmp[idx].first = (currentS - iw < 0) ? 0 : currentS - iw;

        if(tmp[i].first == 0)
            icnt++;
        if(tmp[idx].first == 0)
            icnt++;

        backtracking(idx+1, icnt, tmp);
    }

}

// 계란으로 계란치기
int main(){
    cin >> N;

    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }

    backtracking(0, 0, v);

    cout << CNT << "\n";

    return 0;
}