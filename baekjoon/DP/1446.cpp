// https://www.acmicpc.net/problem/1446
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, dp[10010];
vector<pair<int, int>> vec[10010];


// 지름길
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;

    for(int i = 0; i < n; i++){
        int p, q, r;
        cin >> p >> q >> r;
        vec[q].push_back({p, r});
    }

    for(int i = 1; i <= d; i++){
        dp[i] = dp[i - 1] + 1;
        for(int j = 0; j < vec[i].size(); j++){
            int k = vec[i][j].first;
            int cost = vec[i][j].second;

            dp[i] = min(dp[i], dp[k] + cost);
        }
    }

    cout << dp[d];

    return 0;
}