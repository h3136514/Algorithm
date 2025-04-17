#include <iostream>
#include <vector>

using namespace std;
char board[9][9];
bool visitied[10], check;
vector<pair<int, int>> v;

// 숫자 방문 초기화
void init(){
    for(int i = 0; i < 10; i++)
        visitied[i] = false;
}

// 스도쿠 출력
void priBoard(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
}

// 스도쿠 가능여부
bool checkSudoke(int x, int y){
    // 가로줄 확인
    for(int i = 0; i < 9; i++){
        int num = board[y][i] -'0';
        if(board[y][i] != '0' && visitied[num])
            return false;
        else
            visitied[num] = true;
    }
    init();

    // 세로줄 확인
    for(int i = 0; i < 9; i++){
        int num = board[i][x] -'0';
        if(board[i][x] != '0' && visitied[num])
            return false;
        else
            visitied[num] = true;
    }
    init();

    // 3 * 3 보드확인
    int idxX = x/3, idxY = y/3;
    for(int i = idxY*3; i < (idxY+1)*3; i++){
        for(int j = idxX*3; j < (idxX+1)*3; j++){
            int num = board[i][j] -'0';
            if(board[i][j] != '0' && visitied[num])
                return false;
            else
                visitied[num] = true;
        }
    }
    init();

    return true;
}

void backtracking(int cnt, int idx){
    if(check)   // 기존에 답이 출력됐으면 나머지 함수도 다 종료(시간절약)
        return;

    if(cnt == v.size()){
        priBoard();
        check = true;   // 한 개만 출력(사전식 순서)

        return;
    }

    for(int i = idx; i < v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;

        for(int j = 1; j < 10; j++){
            board[y][x] = j + '0';
        
            if(checkSudoke(x, y)){
                backtracking(cnt+1, i+1);
            }
            
            init();
            board[y][x] = '0';
        }

        return;
    }

}

// 스도쿠
int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> board[i][j];
            if(board[i][j] == '0'){
                v.push_back({j, i});
            }
        }
    }

    backtracking(0, 0);

    return 0;
}