// 누적합
#include <iostream>

using namespace std;
int R, C, Q, r1, c1, r2, c2, num[1001][1001], dp[1001][1001];
long long cnt, sum;

// 어두운 건 무서워
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> Q;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> num[i][j];
            // 누적합 구하기
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + num[i][j];
        }
    }

    for(int i = 1; i <= Q; i++){
        cin >> r1 >> c1 >> r2 >> c2;
        if(r1 == r2 && c1 == c2){
            sum += num[r1][c1];
            cnt++;
        }else{
            sum += dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1];
            cnt += (r2 - r1 + 1) * (c2 - c1 + 1);
        }

        cout << sum/cnt << "\n";
        sum = 0;
        cnt = 0;
    }

    return 0;
}