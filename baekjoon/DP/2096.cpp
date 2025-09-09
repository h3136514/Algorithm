#include <iostream>
#include <algorithm>

using namespace std;
int N, num[100000][3], dp1[3], dp2[3], temp1[3], temp2[3];  // dp1 : 최댓값, dp2 : 최솟값

// 내려가기(메모리 제한: 4MB)
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++)
            cin >> num[i][j];
    }

    dp1[0] = dp2[0] = num[0][0];
    dp1[1] = dp2[1] = num[0][1];
    dp1[2] = dp2[2] = num[0][2];
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
                temp1[j] = max(dp1[0], dp1[1]) + num[i][j];
                temp2[j] = min(dp2[0], dp2[1]) + num[i][j]; 
            }else if(j == 1){
                temp1[j] = max({dp1[0], dp1[1], dp1[2]}) + num[i][j];
                temp2[j] = min({dp2[0], dp2[1], dp2[2]}) + num[i][j]; 
            }else{
                temp1[j] = max(dp1[1], dp1[2]) + num[i][j];
                temp2[j] = min(dp2[1], dp2[2]) + num[i][j]; 
            }
        }

        // 현재 행 업데이트
        for(int j = 0; j < 3; j++){
            dp1[j] = temp1[j];
            dp2[j] = temp2[j];
        }
    }

    cout << max({dp1[0], dp1[1], dp1[2]}) << " " << min({dp2[0], dp2[1], dp2[2]}) << "\n";

    return 0;
}