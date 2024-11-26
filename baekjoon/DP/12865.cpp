#include <iostream>
#include <vector>

using namespace std;
int N, W, V, K, dp[101][100001]; //dp[i][j]: i: 아이템 고려한 수(순서대로)  j: 최대 수용 무게
vector<pair<int, int>> v;

// 평범한 배낭
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> W >> V;
        v.push_back({W, V});
    }

    for(int i = 0; i < v.size(); i++){
        for(int j = 1; j <= K; j++){
            W = v[i].first;
            V = v[i].second;

            if(W <= j) // 배낭에 넣을 수 있을 때
                dp[i+1][j] = max(dp[i][j], dp[i][j-W] + V);
            else    // 배낭에 넣을 수 없을 때
                dp[i+1][j] = dp[i][j];
        }

    }

    cout << dp[N][K] << "\n";

    return 0;
}
