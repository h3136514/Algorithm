#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> boards;
int N, M, CNT;
int offerset_X[4] = {1, 0, -1, 0};
int offerset_Y[4] = {0, 1, 0, -1};

// 다음 위치가 범위를 멋어난 경우 && 발판 유무 체크
bool check(int x, int y) {
    if(x  >= M || y >= N || x < 0 || y < 0 || boards[y][x] == 0)
        return false;
    
    return true;
}

int dfs(int cx, int cy, int nx, int ny) {
    // 현재 위치가 0 이므로 끝
    if((boards[cy][cx] == 0))
        return 0;
    
    int checkCnt = 0;
    // 현재 위치를 기준으로 가능한 방향 모두 확인  
    for(int i =0; i < 4; i++) {
        int nextx = cx + offerset_X[i];
        int nexty = cy + offerset_Y[i];
        
        if(!check(nextx, nexty))
            continue;
    
        boards[cy][cx] = 0;
        int cnt = dfs(nx, ny, nextx, nexty) + 1;
        boards[cy][cx] = 1;
                
        // 현재까지 구한 최대 이동횟수와, 현재 이동횟수를 가지고 최선을 다하는 경우의 이동횟수를 구함
        if(checkCnt % 2 == 0 && cnt % 2 == 1) // 최선의 경우는 현재 플레이어가 지는 경우인데, 현재 플레이어가 승리하는 경우
            checkCnt = cnt;
        else if(checkCnt % 2 == 0 && cnt % 2 == 0)   // 계속 패배하는 경우(지더라도 최선을 다함)
            checkCnt = max(checkCnt, cnt);
        else if(checkCnt % 2 == 1 && cnt % 2 == 1)   // 계속 이기는 경우(빨리 이김)
            checkCnt = min(checkCnt, cnt);
            
    }
    
    return checkCnt;
}


int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    boards = board;
    N = boards.size();
    M = boards[0].size();
    
    CNT = dfs(aloc[1], aloc[0], bloc[1], bloc[0]);  // A부터 시작
    
    return CNT;
}

#include <iostream>

int main()
{
  cout <<solution( {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {1, 0}, {1, 2}) << endl;//출력값 : 5
  cout <<solution( {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {1, 0}, {1, 2}) << endl;//출력값 : 4
  
  return 0;
}