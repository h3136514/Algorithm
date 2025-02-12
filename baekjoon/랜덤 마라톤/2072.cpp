// 구현, 시물레이션
#include <iostream>
#include <queue>

using namespace std;
queue<pair<int, int>> q;
int N, x, y, CNT, TURN = -1, board[20][20], visitied[20][20];
int offer_X[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int offer_Y[8] = {0, 0, 1, -1, 1, -1, -1, 1};

// 오목판 위인지 확인
bool check(int currentX, int currentY){
    return currentX > 0 && currentY > 0 && currentX < 20 && currentY < 20;
}

// 초기화
void init(){
    for(int i = 1; i < 20; i++)
        for(int j = 1; j < 20; j++)
            visitied[i][j] = 0;
    
    q.push({x, y});
    visitied[y][x] = 1;
    CNT = 1;
}

// 연속된 5개의 같은돌인지 탐색(가로, 세로, 대각선)
bool bfs(int target){
    //양옆에 확인
    init();
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 2; i++){
            int ix = cx + offer_X[i];
            int iy = cy + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && board[iy][ix] == target){
                CNT++;
                visitied[iy][ix] = 1;
                q.push({ix, iy});
            }
        }
    }
   
    if(CNT == 5)
        return true;
        
    init();
    // 위아래 확인
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 2; i < 4; i++){
            int ix = cx + offer_X[i];
            int iy = cy + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && board[iy][ix] == target){
                CNT++;
                visitied[iy][ix] = 1;
                q.push({ix, iy});
            }
        }
    }
    if(CNT == 5)
        return true;

    // 오른쪽 대각선확인
    init();
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 6; i < 8; i++){
            int ix = cx + offer_X[i];
            int iy = cy + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && board[iy][ix] == target){
                CNT++;
                visitied[iy][ix] = 1;
                q.push({ix, iy});
            }
        }
    }
    if(CNT == 5)
        return true;

    // 왼쪽 대각선 확인
    init();
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 4; i < 6; i++){
            int ix = cx + offer_X[i];
            int iy = cy + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && board[iy][ix] == target){
                CNT++;
                visitied[iy][ix] = 1;
                q.push({ix, iy});
            }
        }
    }
    if(CNT == 5)
        return true;

    return false;
}

// 오목
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> y >> x;

        if(TURN > 0)
            continue;

        if(i%2 != 0){
            board[y][x] = 1;
            if(bfs(1))
                TURN = i;
        }else{
            board[y][x] = 2;
            if(bfs(2))
                TURN = i;
        }
    }

    cout << TURN << "\n";

    return 0;
}
