// 배낭 문제
// https://www.acmicpc.net/problem/1106
#include <iostream>
#include <vector>

#define INF 200002
using namespace std;
int N, C, dp[2001], result = INF;
vector<int> V[21];

void init(){
    for(int j = 1; j <= 2000; j++){
        dp[j] = INF;
    }
}

// 호텔
int main(){
    cin >> C >> N;
    for(int i = 1; i <= N; i++){
        V[i].resize(2);
        cin >> V[i][0] >> V[i][1];
    }

    init();
    for(int i = 1; i <= N; i++){
        int cost = V[i][0];
        int cnt = V[i][1];

        dp[cnt] = min(dp[cnt], cost);
        for(int j = cnt; j <= 2000; j++){ 
            dp[j] = min(dp[j], dp[j-cnt] + cost);
        }
    }

    for(int i = C; i <= 2000; i++){ // 적어도 C명이므로 돈의 최솟값은 C명을 넘어갈 수 있음
        result = min(result, dp[i]);
    }

    cout << result << "\n";
}