// 구현, 브루트포스
#include <iostream>

using namespace std;
int T;
char board[3][3], target;

bool check(){
    bool result = false;

    for(int j = 0; j < 3; j++){
        // 가로줄 확인
        if(board[j][0] == target && board[j][1] == target && board[j][2] == target)
            return true;
        // 세로줄 확인
        if(board[0][j] == target && board[1][j] == target && board[2][j] == target)
            return true;
    }
    // 대각선 확인
    if((board[0][0] == target && board[1][1] == target && board[2][2] == target) || (board[0][2] == target && board[1][1] == target && board[2][0] == target))
        return true;

    return false;
}

// 출력
void printBoard(){
    for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
            cout << board[j][k];
        }
        cout << "\n";
    }
}

// 틱택토 이기기 
int main(){
    cin >> T;

    for(int i = 1; i <= T; i++){
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                cin >> board[j][k];
        cin >> target;

        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(board[j][k] == '-'){
                    board[j][k] = target;
                    if(check()){
                        cout << "Case " << i <<":\n"; 
                        printBoard();
                    }
                    board[j][k] = '-';
                }
            }
        }
    }

    return 0;
}