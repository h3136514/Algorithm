#include <iostream>

using namespace std;
int N, L, board[101][101], visitied[101][101], CNT;
bool checkR, checkL;

bool check(int startX, int startY, int endX, int endY, int num){
    if(startX < 0 || startY < 0 || endX >= N || endY >= N)
        return false;

    for(int i = startY; i <= endY; i++){
        for(int j = startX; j <= endX; j++){
            if(board[i][j] != num)
                return false;
            if(visitied[i][j])
                return false;
            
            visitied[i][j] = 1;
        }
    }

    return true;
}

// 경사로
int main(){
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        // 행 확인
        checkR = true;
        for(int j = 1; j < N; j++){
            if(board[i][j-1] == board[i][j] || visitied[i][j])
                continue;
            
            if(board[i][j-1] < board[i][j]){
                if(!check(j-L, i , j-1, i, board[i][j]-1)){
                    checkR = false;
                    break;
                }
            }else{
                if(!check(j, i, j+(L-1), i, board[i][j-1]-1)){
                    checkR = false;
                    break;
                }
            }
        }
        if(checkR)
            CNT++;
        // 행 방문 초기화
        for(int j = 0; j < N; j++)
            visitied[i][j] = 0;


        // 열 확인
        checkL = true;
        for(int j = 1; j < N; j++){
            if(board[j-1][i] == board[j][i] || visitied[j][i])
                continue;
            
            if(board[j-1][i] < board[j][i]){
                if(!check(i, j-L , i, j-1, board[j][i]-1)){
                    checkL = false;
                    break;
                }
            }else{
                if(!check(i, j, i, j+(L-1), board[j-1][i]-1)){
                    checkL = false;
                    break;
                }
            }
        }

        // 열 방문 초기화
        if(checkL)
            CNT++;
        for(int j = 0; j < N; j++)
            visitied[j][i] = 0;
    }

    cout << CNT << "\n";

    return 0;
}