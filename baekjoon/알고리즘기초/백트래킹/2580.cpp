#include <iostream>

using namespace std;
int N, board[9][9], tmp[9][9];

// 빈 공간 찾기
void find_position(int& x, int& y) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                x = j;
                y = i;

                return;
            }
        }
    }
    //빈공간 없음
    x = -1;
    y = -1;
}

// 해당 수를 넣을 수 있는지 확인
bool check(int x, int y, int num) {
    // 가로, 세로 체크
    for (int i = 0; i < 9; i++) {
        if (board[i][x] == num || board[y][i] == num) {
            return false;
        }
    }
    // 3X3박스에 있는지 확인
    int startX = x - x % 3;
    int startY = y - y % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startY + i][startX + j] == num)
                return false;
        }
    }

    return true;
}

// 백트래킹
void sudoku() {
    int x, y;
    find_position(x, y);
   
    if (x == -1 && y == -1) {
        // 배열 복사
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                tmp[i][j] = board[i][j];
            }
        }
        return;
    }

    for (int i = 1; i < 10; i++) {
        if (!check(x, y, i))
            continue;

        board[y][x] = i;
        sudoku();
        board[y][x] = 0;
    }

}

// 스도쿠
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    sudoku();
  
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}