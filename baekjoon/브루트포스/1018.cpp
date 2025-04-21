#include <iostream>

using namespace std;
int N, M, sum = 987654321;
char board[51][51];

// 8 * 8 영역 체스판 일치 확인
void play(char c){
    int startX = 0, startY = 0, endX = 7, endY = 7;
    while(endY < N){
        int cnt = 0;
        char reC = (c == 'W') ? 'B' : 'W';

        for(int i = startY; i <= endY; i++){
            char s = (i % 2 == 0) ? c : reC;
            for(int j = startX; j <= endX; j++){
                if(s != board[i][j])
                    cnt++;
                
                s = (c == s) ? reC : c;
            }
        }

        if(endX == M -1){
            startX = 0, endX = 7;
            startY++, endY++;
        }else{
            startX++, endX++;
        }

        sum = min(sum, cnt);
    }
}

// 체스판 다시 칠하기 
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

   play('W');   // 맨 처음 W로 시작했을 때
   play('B');   // 맨 처음 B로 시작했을 때

    cout << sum << "\n";

    return 0;
}