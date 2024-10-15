#include <iostream>
#include <vector>

using namespace std;
int N, t, p, sum, dp[1006];
vector<int> v[1001];

// 퇴사
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> t >> p;
        v[i].push_back(t);
        v[i].push_back(p);
    }

    for(int i = 1; i <= N; i++){
        t = v[i][0];
        p = v[i][1];
        dp[i] = max(dp[i], dp[i-1]); // 이전에 한 금액이 더크면 그걸로 갱신(중첩)
        dp[i+t] = max(dp[i+t], dp[i] + p);  //t일뒤에 지금+금액을 했을때와 다른날에서 t일뒤에 했을때를 비교해서 최댓값 갱신
    }

    cout << max(dp[N], dp[N+1])<<"\n";

    return 0;
}