// 누적합
#include <iostream>

using namespace std;
int N, M, a, b, A[100001], dp[100001];

// 합 구하기
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    
    for(int i = 1; i <= N; i++)
        dp[i] = dp[i-1] + A[i];
    
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;

        cout << dp[b] - dp[a-1] << "\n";
    }

    return 0;
}