#include <iostream>

using namespace std;
int N, M, K, cnt, sum;
char board[1001][5001];

// 우당탕탕 영화예매
int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> board[i][j];

    for(int i = 0; i < N; i++){
        cnt = 0;
        for(int j = 0; j < M; j++){
            if(board[i][j] == '1'){
                cnt = 0;
                continue;
            }
            if(cnt < K)
                cnt++;
            if(cnt == K)
                sum++;
        }
    }

    cout << sum << "\n";

    return 0;
}