#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, dp[101], CNT;
vector<pair<int, int>> v;

// 전깃줄
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    dp[0] = 1;
    CNT = dp[0];
    for(int i = 1; i < N; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(v[i].second > v[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        CNT = max(CNT, dp[i]);  // 가장 긴 증가하는 부분수열 구하기
    }

    cout << N - CNT << "\n";

    return 0;
}