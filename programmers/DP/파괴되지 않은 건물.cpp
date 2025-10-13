// 누적 합
// https://school.programmers.co.kr/learn/courses/30/lessons/92344
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int N, M, answer = 0;
int dp[1002][1002];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    N = board.size();
    M = board[0].size();
    
    for(int i = 0; i < skill.size(); i++){
        int typ = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = (typ == 1) ? -skill[i][5] : skill[i][5];
        
        dp[r1][c1] += degree;
        dp[r2+1][c1] -= degree;
        dp[r1][c2+1] -= degree;
        dp[r2+1][c2+1] += degree;
    }
    
    // 행 누적합
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < M; j++){
            dp[i][j+1] += dp[i][j];
        }
    }
    
    // 열 누적합
    for(int i = 0; i <= M; i++){
        for(int j = 0; j < N; j++){
            dp[j+1][i] += dp[j][i];
        }
    }
    
    // 총합
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            board[i][j] += dp[i][j];
          
            if(board[i][j] > 0)
                answer++;
        }
    }
    
    
    return answer;
}