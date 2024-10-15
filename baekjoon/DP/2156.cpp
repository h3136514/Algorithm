#include <iostream>

using namespace std;
int N, num[10001],sum;
int dp1[10001], dp2[10001]; // dp1: 연속으로 하나만 마신 상태, dp2: 연속으로 두번 마신 상태

// 포도주 시식
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }

    if(N == 1){
        cout << num[0] << "\n";
    }else if(N == 2){
        cout << num[0] + num[1] << "\n";
    }else{
        dp1[0] = num[0];
        dp2[0] = num[0];
        dp1[1] = num[1];
        dp2[1] = dp1[0] + num[1];

        for(int i = 2; i < N; i++){
            dp1[i] = max(dp1[i-2]+ num[i], dp2[i-2]+ num[i]);  // 연속으로 못 마심(한번 마신 상태)
            dp2[i] = max(dp1[i-1] + num[i], dp2[i-1]); // 연속으로 마시거나 또는 안마심(두번 마신 상태)

        }

        for(int i = 0; i < N; i++){
            sum = max(sum, dp1[i]);
            sum = max(sum, dp2[i]);
        }

        cout << sum << "\n";
    }

    return 0;
}