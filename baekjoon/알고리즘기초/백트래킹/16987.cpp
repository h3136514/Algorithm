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
    if(currentS <= 0){
        backtracking(idx+1, cnt, egg);
        return;
    }

    bool check = false;
    for(int i = 0; i < N; i++){
        int is = egg[i].first;
        int iw = egg[i].second;
        int icnt = cnt;
    
        if(i==idx)
            continue;

        if(is <= 0){
            if(i == N-1){
                backtracking(idx+1, cnt, egg);
            }
            continue;
        }

        egg[i].first =  is - currentW;
        egg[idx].first = currentS - iw;

        if(egg[i].first <= 0){
            icnt++;
            check = true;
        }
        if(egg[idx].first <= 0){
            icnt++;
            check = true;
        }

        backtracking(idx+1, icnt, egg);

        egg[i].first =  is;
        egg[idx].first = currentS;
    }

    if(!check)
       backtracking(idx+1, cnt, egg);
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