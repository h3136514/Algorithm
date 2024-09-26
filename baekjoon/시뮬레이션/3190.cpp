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