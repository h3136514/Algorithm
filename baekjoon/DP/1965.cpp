#include <iostream>

using namespace std;
int N, num[1001], dp[1001], maxN = 1;

// 상자넣기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    dp[0] = 1;
    for(int i = 1; i < N; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(num[i] > num[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxN = max(maxN, dp[i]);
    }

    cout << maxN << "\n";

    return 0;
}