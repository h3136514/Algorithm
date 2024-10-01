#include <iostream>


using namespace std;
int N, num[301], sum;
int dp1[301];   //이미 연속으로 뛰었을때의 최댓값
int dp2[301];   //2칸씩 뛰었을때의 최댓값

void stair() {
    if(N == 1) {
        sum = num[0];
        return;
    }else if(N == 2) {
        sum = num[0] + num[1];
        return;
    }

    // 초기 값
    dp1[0] = num[0];
    dp2[0] = num[0];
    dp1[1] = num[0] + num[1];
    dp2[1] = num[1];
    for(int i = 2; i < N; i++) {
        dp1[i] = dp2[i-1] + num[i];     // 연속으로 가야됨(2칸 뛴 경우에서 1칸 감)
        dp2[i] = max(dp1[i-2], dp2[i-2]) + num[i];  // 두칸 가야됨(아무 경우에서나 갈 수 있음)
    }

    // 최댓값
    sum = max(dp1[N-1], dp2[N-1]);
}

// 계단 오르기 
int main() {
    cin >> N;
    for(int i =0; i < N; i++) {
        cin >> num[i];
    }
    
    stair();
    cout << sum << "\n"; 

    return 0;
}