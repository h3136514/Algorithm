#include <string>
#include <vector>

using namespace std;
int N, queen[12][12];

// 퀸을 안전하게 배치할 수 있는지 확인하는 함수
bool isCheckPosition(int col, int row) {
    // 현재 행에 이미 다른 퀸이 있는지 확인
    for(int i = 0; i < N; i++) {
        if(queen[col][i] || queen[i][row])
            return false;
    }
    
    // 대각선에 다른 퀸이 있는지 확인
    // 대각선 밑에 확인
    for(int i = 0; i <= col; i++) {
        if(row - i >= 0 && queen[col - i][row -i]) 
            return false;
        if(row + i < N && queen[col - i][row + i])
            return false;
    }
    // 대각선 위에 확인
    for(int i = col; i < N; i++) {
        if(row - (i - col) >= 0 && queen[i][row - (i - col)])
            return false;
        if(row +(i - col) < N && queen[i][row + (i - col)])
            return false;
    }
    
    return true;
}

// 퀸을 배치하는 함수(최대 N이 조금만 더컸으면 long long으로 했어야함)
int placeQueens(int col) {
    if(col == N)
        return 1;
    
    int cnt = 0;
    for(int row = 0; row < N; row++) {
        // 퀸을 놓을수 있는 위치인 경우 퀸을 놓음
        if(isCheckPosition(col, row)) {
            queen[col][row] = 1;
            cnt += placeQueens(col + 1);
            queen[col][row] = 0;
        }
    }
    
    return cnt;
}

// 체스판의 가로 세로의 세로의 길이 n이 매개변수로 주어질 때, n개의 퀸이 조건에 만족 하도록 배치할 수 있는 방법의 수를 반환 (시간복잡도 : O(N!))
int solution(int n) {
    N = n;
    int answer = placeQueens(0);

    return answer;
}


#include <iostream>

int main()
{
  cout << solution(4) << endl; // 출력값 : 2
  return 0;
}