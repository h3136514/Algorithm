#include <iostream>
#include <string>
#include <queue>

using namespace std;
int selected[5][5], visited[5][5], CNT;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string S[5];
queue<pair<int, int>> q;

bool check(int x, int y){
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

void init(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            visited[i][j] = 0;
        }
    }
}

bool isConnected(){
    init();
    
    // 첫 번째 선택된 칸 찾기
    int startX = -1, startY = -1;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(selected[i][j]){
                startX = i;
                startY = j;
                break;
            }
        }
        if(startX != -1) break;
    }
    
    // BFS로 연결성 확인
    q.push({startX, startY});
    visited[startX][startY] = 1;
    int cnt = 1;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(check(nx, ny) && selected[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    
    return cnt == 7;
}

int countS(){
    int cnt = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(selected[i][j] && S[i][j] == 'S'){
                cnt++;
            }
        }
    }
    return cnt;
}

void backtrack(int pos, int selectedCnt){
    if(selectedCnt == 7){
        if(isConnected() && countS() >= 4){
            CNT++;
        }
        return;
    }
    
    if(25 - pos < 7 - selectedCnt){
        return;
    }
    
    if(pos < 25){
        int x = pos / 5;
        int y = pos % 5;
        
        // 현재 칸 선택
        selected[x][y] = 1;
        backtrack(pos + 1, selectedCnt + 1);
        selected[x][y] = 0;
        
        // 현재 칸 선택하지 않음
        backtrack(pos + 1, selectedCnt);
    }
}

int main(){
    for(int i = 0; i < 5; i++){
        cin >> S[i];
    }
    
    backtrack(0, 0);
    
    cout << CNT << "\n";
    
    return 0;
}