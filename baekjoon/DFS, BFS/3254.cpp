#include <iostream>
#include <queue>

using namespace std;
int board[6][7], si, ji, CNT;
int offer_X[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int offer_Y[8] = {1, -1, 0, 0, -1, 1, 1, -1};
bool isSk, isJi;
queue<pair<pair<int, int>, pair<int, int>>> q;

bool check(int x, int y){
    return x >= 0 && x < 7 && y >= 0 && y < 6;
}

//
int checkFour(int startX, int startY, int d, int target){
    int cnt = 1;
    int ix = startX, iy = startY;
    while(check(ix + offer_X[d], iy + offer_Y[d]) && board[iy + offer_Y[d]][ix + offer_X[d]] == target){
        ix += offer_X[d], iy += offer_Y[d];
        cnt++;
    }
    ix = startX, iy = startY;
    while(check(ix + offer_X[d+1], iy + offer_Y[d+1]) && board[iy + offer_Y[d+1]][ix + offer_X[d+1]] == target){
        ix += offer_X[d+1], iy += offer_Y[d+1];
        cnt++;
    }

    return cnt;
}

bool checkGimbob(int startX, int startY){
    int target = board[startY][startX]; 
    // 위아래 확인
    // 가로세로 확인
    // 좌상향 대각선 확인
    // 우상향 대각선 확인
    for(int i = 0; i <8; i+= 2){
        if(checkFour(startX, startY, i, target) >= 4){
            return true;
        }
    }

    return false;
}

// 김밥 21개
int main(){
    for(int i = 1; i <= 21; i++){
        cin >> si >> ji;
        if(isSk || isJi)
            continue;
        
        si--;
        ji--;
        for(int j = 0; j <6; j++){
            if(board[j][si] != 0)
                continue;
            board[j][si] = 1;
            if(checkGimbob(si, j)){
                CNT = i;
                isSk = true;
            }
            break;
        }

        if(!isSk){
            for(int j = 0; j < 6; j++){
                if(board[j][ji] != 0)
                    continue;

                board[j][ji] = 2;
                if(checkGimbob(ji, j)){
                    CNT = i;
                    isJi = true;
                }
                break;
            }
        }
    }

    if(isSk)
        cout << "sk " << CNT << "\n";
    else if(isJi)
        cout << "ji " << CNT << "\n";
    else
        cout <<"ss\n";
    
    return 0;
}