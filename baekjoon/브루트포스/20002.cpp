#include <iostream>
#include <queue>

using namespace std;
int N, num[301][301], dp[301][301], maxNum= -1001;

// 최대 정사각형 합 구하기
void trial(int n){
    int sum = 0;
    int col = n;
    int row = n;
    while(col <= N){
        sum = dp[col][row] - dp[col-n][row] - dp[col][row-n] + dp[col-n][row-n];

        maxNum = max(maxNum, sum);

        if(row + 1 > N){  // 맨오른쪽 구간을 넘음
            row = n;
            col++;   
        }else{
            row++;  //오른쪽으로 한칸 이동
        }
    }
}

// 사과나무 ( K × K 의 크기의 정사각형 모양으로만 수확해서 가장 큰 최댓값)
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> num[i][j];
        }
    }

    // 누적합 계산
    for(int i = 1; i <= N; i++){    // 맨 끝부분 계산
        dp[i][1] = dp[i-1][1] + num[i][1];
        dp[1][i] = dp[1][i-1] + num[1][i];
    }

    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= N; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j] -dp[i-1][j-1] + num[i][j];   //-dp[i-1][j-1] : 중복구간 제거 
        }
    }

    for(int i = 1; i <= N; i++)
        trial(i);

    cout << maxNum << "\n";

    return 0;
}