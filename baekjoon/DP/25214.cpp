#include <iostream>

#define MAX 1000000001
using namespace std;
int N, a, minA = MAX, dp[200001];

// 크림 파스타
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a;

        minA = min(minA, a);
        if(i != 0)
            dp[i] = (a - minA) > dp[i-1] ? a - minA : dp[i-1];

        cout << dp[i] << " ";
    }

    return 0;
}