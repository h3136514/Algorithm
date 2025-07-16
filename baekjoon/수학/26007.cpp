// 누적 합
#include <iostream>
#include <vector>

using namespace std;
int N, M, K, X, a, b, num[100001], dp[100001];
vector<int> v;

// Codepowers 
int main() {
    cin >> N >> M >> K >> X;
    num[0] = X;
    for (int i = 1; i <= N; i++) {
        cin >> num[i];
        num[i] += num[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        if (num[i] < K)
            dp[i]++;
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v.push_back(dp[b - 1] - dp[a - 1]);
    }

    for (int i = 0; i < M; i++) {
        cout << v[i] << "\n";
    }

    return 0;
}