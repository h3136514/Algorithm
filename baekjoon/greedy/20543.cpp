// 누적 합
#include <iostream>

using namespace std;
int N, M;
long long board[2001][2001], boom[2001][2001];

// 폭탄 던지는 태영이
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            board[i][j] *= -1;
        }
    }

    int r = M/2;
    int s = r, e = N-r;

    for(int i = s; i < e; i++){
        for(int j = s; j < e; j++){
            // (i-r, j-r)를 좌상단을 기준으로 누적합 계산
            boom[i][j] = board[i-r][j-r];

            // 누적합 실시
            if(i-r-1 >= 0)
                boom[i][j] -= board[i-r-1][j-r];
            if(j-r-1 >= 0)
                boom[i][j] -= board[i-r][j-r-1];
            if((i-r-1 >= 0) && (j-r-1 >= 0))    // 중복 값 복원
                boom[i][j] += board[i-r-1][j-r-1];
            
            // M 간격으로 이전 결과 누적
            if(i-M >= 0)
                boom[i][j] += boom[i-M][j];
            if(j-M >= 0)
                boom[i][j] += boom[i][j-M];
            if((i-M >= 0) && (j-M >= 0))    // 중복 값 제거
                boom[i][j] -= boom[i-M][j-M];
        }
    }

    // 값 출력
     for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << boom[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}