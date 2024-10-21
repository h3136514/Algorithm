#include <iostream>
#include <string>

using namespace std;
string board;

bool gameCheck(){
    int x = 0;
    int o = 0;
    int blank = 0;
    for(int i = 0; i < board.size(); i++){
        if(board[i] == 'X')
            x++;
        if(board[i] == 'O')
            o++;
        if(board[i] == '.')
            blank++;

    }

    if(x < o || x-o > 1)   // 'X'를 먼저 놓으므로 'O'는 더 많을 수 없다.('X'는 최대 1개 더 많을 수 있다.)
        return false;
    
    bool xWin = false;
    bool oWin = false;
    // 대각선 승리 확인
    if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
        xWin = true;
    else if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
        oWin = true;
    if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
        xWin = true;
    else if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
        oWin = true;

    int xCNT = 0, oCNT = 0;
    for(int i = 0; i < 9; i += 3){
        // 가로줄 승리확인
        xCNT = 0, oCNT = 0;
        for(int j = i; j < i+3; j++){
            if(board[j] == 'X')
                xCNT++;
            if(board[j] == 'O')
                oCNT++;
        }
        if(xCNT == 3)
            xWin = true;
        else if(oCNT == 3)
            oWin = true;

        // 세로줄 승리확인
        xCNT = 0, oCNT = 0;
        for(int j = i/3; j <= i/3 + 6; j+=3){
            if(board[j] == 'X')
                xCNT++;
            if(board[j] == 'O')
                oCNT++;
        }
        if(xCNT == 3)
            xWin = true;
        else if(oCNT == 3)
            oWin = true;
    }

    if((xWin && oWin) || (blank && (!xWin && !oWin))) //둘다 승리하거나 게임판이 가득안찼는데 둘다 승리를 못한 경우
        return false;
    if((xWin && x != o+1 )|| (oWin && x != o))  // 'X'차례에서 이길 경우 갯수는 'O'보다 하나 더 많아야 하고 'O'차례에서 이길 경우 갯수는 'X'와 같아야한다.
        return false;
    
    return true;

}

// 틱택토 (3×3 격자판에서 첫 번째 사람이 X를 놓고 두 번째 사람이 O를 놓는다. 한 사람의 말이 가로, 세로, 대각선 방향으로 3칸을 잇거나 게임판이 가득 차면 게임이 끝날 때 =>  발생할 수 있는 최종 상태인지를 판별하시오.)
int main(){
    while(true){
        cin >> board;
        if(board == "end")
            break;
        
        if(gameCheck())
            cout << "valid\n";
        else
            cout << "invalid\n";
    }

    return 0;
}