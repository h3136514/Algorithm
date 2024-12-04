#include <iostream>
#include <string>
#include <algorithm>

#define INF 999999999999999
using namespace std;
int T, N, minNum[8] = {0, 0, 1, 7, 4, 2, 0, 8};
string maxNum;
long long dp[101];

// 가장 큰 수 만들기
void maxCal(int num){
    while(num > 0){
        if(num == 3){   // num이 홀수일 때
            maxNum += "7";
            num = 0;
        }else{
            maxNum += "1";
            num -= 2;
        }
    }

    reverse(maxNum.begin(), maxNum.end());
}

// 가장 작은 수 만들기
void minCal(){
    for(int i = 0; i < 101; i++)
        dp[i] = INF;
    
    // dp[n]을 n개의 성냥으로 구성 가능한 최솟값
    dp[1] = 9, dp[2] = 1, dp[3] = 7, dp[4] = 4, dp[5] = 2, dp[6] = 6, dp[7] = 8;
    for(int i = 8; i <= 100; i++)
        for(int j = 2; j <= 7; j++)
            dp[i] = min(dp[i], dp[i-j]*10 + minNum[j]);
}

// 성냥개비
int main(){
    cin>> T;
    minCal();
    while(T--){
        cin >> N;

        maxCal(N);

        cout << dp[N] << " ";
        cout << maxNum << "\n";

        maxNum = "";
    }

    return 0;
}