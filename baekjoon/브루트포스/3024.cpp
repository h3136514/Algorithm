#include <iostream>
#include <set>

using namespace std;
int N;
char board[31][31];
set<char> s;
bool check;

bool checkTicTacTok(char c){
    for(int i = 0; i < N; i++){
        // 가로 줄 확인
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(board[i][j] == c)
                cnt++;
            else
                cnt = 0;
            if(cnt == 3)
                return true;
        }
   
        // 세로 줄 확인
        cnt = 0;
        for(int j = 0; j < N; j++){
            if(board[j][i] == c)
                cnt++;
            else
                cnt = 0;
            if(cnt == 3)
                return true;
        }
    }

    // 대각선 줄 확인(3*3)
    int endX = 1, endY = 1;
    while (endY + 1 < N){
        // 오른쪽 방향 확인
        if(board[endY][endX] == c && board[endY-1][endX-1] == c && board[endY+1][endX+1] == c)
            return true;

        // 왼쪽 방향
        if(board[endY][endX] == c && board[endY-1][endX+1] == c && board[endY+1][endX-1] == c)
            return true;

        if(endX+1 == N-1){
            endX = 1;
            endY++;
        }else{
            endX++;
        }
    }
    
    return false;
}

// 마라톤 틱택토
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
            s.insert(board[i][j]);
        }
    }

    for(char c : s){
        if(c == '.')
            continue;
        
        if(checkTicTacTok(c)){
            check = true;
            cout << c << "\n";
            break;
        }
    }

    if(!check)
        cout << "ongoing\n";

    return 0;
}