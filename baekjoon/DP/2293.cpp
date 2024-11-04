#include <iostream>
#include <vector>

using namespace std;
int N, K, num, dp[10001];
vector<int> v;

// 동전 1
int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> num;
        v.push_back(num);
    }

    dp[0] = 1;  // 어떤 동전도 사용하지 않는 경우
    for(int i = 0; i < v.size(); i++){
        for(int j = v[i]; j <= K; j++){
            dp[j] += dp[j - v[i]];
        }
    }

    cout << dp[K] << "\n";

    return  0;
}