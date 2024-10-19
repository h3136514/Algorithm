#include <iostream>

using namespace std;
int N;
long long dp1[91], dp2[91];    //dp1: 뒤에가 1로끝나는 수(이제 0만 추가가능), dp2: 뒤에가 0으로 끝나는 수(0, 1추가가능) (int형 범위 초과)

// 이친수 (이진수 중 0으로 시작 X, 1이 두 번 연속X 수)
int main(){
    cin >> N;

    dp1[1] = 1; // 1
    dp2[2] = 1; // 10
    for(int i = 3; i <= N; i++){
        dp2[i] = dp2[i-1]+ dp1[i-1];    
        dp1[i] = dp2[i-1];
    }

    cout << dp1[N] + dp2[N] << "\n";

    return 0;
}