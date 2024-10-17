#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int board[102][102], visitied[102][102], CNT;
int offer_X[8] = {0, 1, 0, -1, -1, 1, 1, -1};
int offer_Y[8] = {1, 0, -1, 0, 1, -1, 1, -1};
queue<pair<int, pair<int,int>>> q;

// 범위 체크
bool check(int x, int y){
    return x > 0 && x <= 101 && y > 0 && y <= 101;
}

// 가장자리 체크
bool checkEdge(int x, int y){
    for(int i = 0; i < 8; i++){
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];
        
        if(board[iy][ix] == 0)
            return true;
    }
    
    return false;
}

void bfs(int startX, int startY, int targetX, int targetY){
    q.push({0, {startX, startY}});
    visitied[startY][startX] = 1;
    
    while(!q.empty()){
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        int cnt = q.front().first;
        q.pop();
        
        if(currentX == targetX && currentY == targetY){
            CNT = cnt/2;
            return;
        }
        
        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            
            if(check(ix, iy) && !visitied[iy][ix] && board[iy][ix] == 1 && checkEdge(ix, iy)){
                visitied[iy][ix] = 1;
                q.push({cnt+1, {ix, iy}});
            }
        }
    }
}


int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 삼각형 채우기(범위2배로 => 가장자리가 겹치는 부분을 없애기 위해서 )
    for(vector<int> v : rectangle){
        for(int i = v[1]*2; i<=v[3]*2; i++){
            for(int j = v[0]*2; j<=v[2]*2; j++){
                board[i][j] = 1;
            }
        }
    }
    
    bfs(characterX*2, characterY*2, itemX*2, itemY*2);
    
    return CNT;
}