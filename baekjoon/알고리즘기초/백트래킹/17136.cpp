#include <iostream>

#define INF 987654321
using namespace std;
int board[10][10], tle[6], totall, minCNT = INF;

void copyed(int x1, int y1, int x2, int y2){
    for(int i = y1; i <= y2; i++){
        for(int j = x1; j <= x2; j++){
            board[i][j] = 2;  // 색종이 붙임 표시(곁치지 않기 위해서)
        }
    }
}

void pasted(int x1, int y1, int x2, int y2){
    for(int i = y1; i <= y2; i++){
        for(int j = x1; j <= x2; j++){
            board[i][j] = 1;
        }
    }
}

// 색종이 붙이기 가능여부
bool check(int x1, int y1, int x2, int y2){
    if(x2 >= 10 || y2 >= 10)
        return false;

    for(int i = y1; i <= y2; i++){
        for(int j = x1; j <= x2; j++){
            if(board[i][j] != 1)
                return false;
        }
    }
    return true;
}

void dfs(int cnt, int sum){
    if(cnt >= minCNT)
        return;

    if(totall == sum){
        minCNT = min(minCNT, cnt);
        return;
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(board[i][j] == 1) {
                int y = i;
                int x = j;
                // 격자 크기별 색종이 탐색
                for(int size = 5; size > 0; size--){
                    int endX = x + size - 1, endY = y + size - 1;
                    // 색종이를 붙일 수 있으면
                    if(tle[size] && check(x, y, endX, endY) && (totall >= sum + size*size)){
                        copyed(x, y, endX, endY);
                        tle[size]--;
                        dfs(cnt+1, sum + size*size);
                        tle[size]++;
                        pasted(x, y, endX, endY);
                    }
                }

                return; //어차피 색종이를 다대입 시킨 후로는 더이상 반복문 돌 필요없음
            }
        }
    }
}

// 색종이 붙이기
int main(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> board[i][j];
            if(board[i][j])
                totall++;
        }
    }
    // 색종이 수 저장
    for(int i = 1; i < 6; i++)
        tle[i] = 5;

    dfs(0, 0);

    if(minCNT == INF)
        minCNT = -1;

    cout << minCNT << "\n";

    return 0;
}