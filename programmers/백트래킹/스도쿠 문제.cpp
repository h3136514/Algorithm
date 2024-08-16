#include <vector>

using namespace std;
vector<vector<int>> board;

// 특정 위치에 숫자를 놓을 수 있는지 확인
bool is_valid(int num, int row, int col) {
    // 같은 행,열에 해당 숫자가 있는지 확인
    for(int i = 0; i < 9; i++) {
        if(board[row][i] == num || board[i][col] == num)
            return false;
    }

    // 3X3박스에 있는지 확인
    int startRow = row - row%3;
    int startCol = col - col%3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

// 숫자가 입력되지 않은 위치를 확인
pair<int, int> find_position() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(board[i][j] == 0)
                return {i, j};
        }
    }

    return {-1, -1};
}

void sudoku() {
    pair<int, int> pos = find_position();
    int row = pos.first;
    int col = pos.second;

    // 이미 모든 칸이 채워져 있음
    if(row == -1)
        return;
    
    for(int num = 1; num <= 9; num++) {
        if(is_valid(num, row, col)) {
            board[row][col] = num;
            sudoku();
            // 스도쿠가 완성된 경우 더이상 탐색하지 않기 위핸 조건
            if(find_position().first == -1)
                return;

            board[row][col] = 0;   
        }
    }
}

// 스도쿠를 완성하기(단, 스도쿠를 완성하지 못하는 board는 주어지지 않음) (시간복잡도 : O(9^N))
vector<vector<int>> solution(vector<vector<int>> input_board) {
  // 인자로 받은 보드를 전역 변수에 복사하고 스도쿠 진행
  board = input_board; 
  sudoku();
  return board;
}



#include <iostream>


void print(vector<vector<int>> vecs)
{
    for(vector<int> vec : vecs) {
        cout << vec[0];
        for(int i =1; i < vec.size(); i++){
            cout << " " << vec[i];
        }
        cout << endl;
    }
}

int main()
{
  print(solution({
                    {5, 3, 0, 0, 7, 0, 0, 0, 0},
                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9}
                }));

  /*
    출력값
    5 3 4 6 7 8 9 1 2 
    6 7 2 1 9 5 3 4 8 
    1 9 8 3 4 2 5 6 7 
    8 5 9 7 6 1 4 2 3 
    4 2 6 8 5 3 7 9 1 
    7 1 3 9 2 4 8 5 6 
    9 6 1 5 3 7 2 8 4 
    2 8 7 4 1 9 6 3 5 
    3 4 5 2 8 6 1 7 9 
  */
  print(solution({
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0}
                }));
                
  /*
    출력값
        1 2 3 4 5 6 7 8 9 
        4 5 6 7 8 9 1 2 3 
        7 8 9 1 2 3 4 5 6 
        2 1 4 3 6 5 8 9 7 
        3 6 5 8 9 7 2 1 4 
        8 9 7 2 1 4 3 6 5 
        5 3 1 6 4 2 9 7 8 
        6 4 2 9 7 8 5 3 1 
        9 7 8 5 3 1 6 4 2 
  */
  return 0;
}