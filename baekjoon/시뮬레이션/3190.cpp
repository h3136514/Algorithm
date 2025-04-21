#include <iostream>
#include <queue>

using namespace std;
int N, L, K, D, row, col, X, snackX = 1, snackY = 1, board[101][101], CNT;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
char C;
queue<pair<int, int>> snake;
queue<pair<int, char>> rotateS;

// 벽 확인
bool check(int x, int y){
    return x > 0 && x <= N && y > 0 && y <= N;
}

// 뱀
int main(){
    cin >> N;
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> col >> row;
        board[col][row] = 1;    // 사과 : 1
    }
    cin >> L;
    for(int i = 0; i < L; i++){
        cin >> X >> C;
        rotateS.push({X, C});
    }

    // 처음 뱀의 위치 대입
    snake.push({snackX, snackY});
    board[snackY][snackX] = 2;  // 뱀 : 2
    D = 0;  // 오른쪽

    while(true){
        CNT++;
        int x = snackX + offer_X[D];
        int y = snackY + offer_Y[D];
        // 가야할 곳이 벽 or 자기 몸일 때
        if(!check(x, y)|| board[y][x] == 2)
            break;

        // 뱀 이동
        if(board[y][x] != 1){   // 사과가 없을 경우(뱀의 꼬리 부분을 줄임(길이변화X))
            int ix = snake.front().first;
            int iy = snake.front().second;
            board[iy][ix] = 0;
            snake.pop();
        }
        snake.push({x, y});
        snackX = x, snackY = y;
        board[snackY][snackX] = 2;

        // 뱀 방향확인
        if(!rotateS.empty()){
            if(CNT == rotateS.front().first){
                char id = rotateS.front().second;
                if(id == 'D')
                    D = (D+1 >= 4) ? 0 : D + 1; // 시계방향 90도
                else
                    D = (D-1 < 0) ? 3 : D - 1;  // 반시계방향 90도

                rotateS.pop();
            }
        }

    }
    
    cout << CNT << "\n";

    return 0;
}

/*
#include <iostream>
#include <queue>

using namespace std;
int N, K, L, X, x, y, R, CNT, num[102][102];
int offer_X[4] ={1, 0, -1, 0};
int offer_Y[4] ={0, 1, 0, -1};
char C;
queue<pair<int, int>> snake;    // 뱀의 몸길이의 영역을 나타냄(꼬리 위치)
queue<pair<int, char>> rotates; // 회전 순서

// 사과 확인
bool checkApple(int ix, int iy) {
    if(num[iy][ix] == 2)
        return true;
    return false;
}

//회전 확인
void checkRotate() {
    if(rotates.empty())
        return;
    
    int a = rotates.front().first;
    char b = rotates.front().second;
    if(CNT <= a)
        return;
    
    rotates.pop();

    if(b == 'L') {  //오른쪽 회전(구현한 보드 구성이 반대이므로 반대)
        R = (R == 0) ? 3 : R - 1; 
    }else {     // 왼쪽 회전
        R = (R == 3) ? 0 : R + 1; 
    }
}

void dummy() {
    snake.push({1, 1});
    num[1][1] = 1;
    x = 1;
    y = 1;
    CNT =1;
    while (!snake.empty()) {
        // 해당방향으로 몸을 늘렸을 때 위치
        int nextX = x + offer_X[R];
        int nextY = y + offer_Y[R];
    
        // 자기자신 or 벽이면 끝
        if(num[nextY][nextX] == 1)
            break;
        
        // 사과가 없으면
        if(!checkApple(nextX, nextY)) {
            // 뱀의 꼬리 위치
            int ix = snake.front().first;
            int iy = snake.front().second;
            num[iy][ix] = 0;    //꼬리를 움직임
            snake.pop();
        }
        snake.push({nextX, nextY});
        num[nextY][nextX] = 1;
        x = nextX;
        y = nextY;

        CNT++;
        checkRotate();
    }
    
}

// 뱀 
int main() {
    cin >> N;
    // 보드의 상하조우 끝에 벽
    for(int i =0; i <= N+1; i++) {
        num[i][0] = 1;
        num[0][i] = 1;
        num[N+1][i] = 1;
        num[i][N+1] = 1;
    }
    cin >> K;
    //사과는 2라고 가정
    for(int i =0; i < K; i++) {
        cin >> y >> x;
        num[y][x] = 2;
    }
    cin >> L;
    for(int i =0; i < L; i++) {
        cin >> X >> C;
        rotates.push({X, C});
    }

    R = 0;   //회전(처음에 오른쪽)
    
    dummy();
    cout << CNT << "\n";

    return 0;
}
    */