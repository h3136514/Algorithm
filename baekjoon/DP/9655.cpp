#include <iostream>
#include <algorithm>

using namespace std;
int N, dp[1001];

// 돌 게임
int main(){
    cin >> N;
    if(N%2 == 0)
        cout << "CY\n";
    else
        cout << "SK\n";

    return 0;
}

/*
int main(){
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= N; i++)
        dp[i] = min(dp[i-1]+1, dp[i-3]+1);

    if(dp[N]%2 == 0)
        cout << "CY\n";
    else
        cout << "SK\n";

    return 0;
}

*/