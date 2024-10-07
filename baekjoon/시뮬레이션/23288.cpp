#include <iostream>
#include <queue>

using namespace std;
int N, M, K, D, X, Y, sum, tmp[6], num[21][21], visitied[21][21];
int offer_X[4] ={1, 0, -1, 0};
int offer_Y[4] ={0, 1, 0, -1};
int dice[6] = {1, 2, 3, 4, 5, 6};
int diceRotate[4][6] ={
    {3, 1, 0, 5, 4, 2},
    {1, 5, 2, 3, 0, 4},
    {2, 1, 5, 0, 4, 3},
    {4, 0, 2, 3, 5, 1}
};
queue<pair<int, int>> q;

// 방문 초기화
void init(){
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
            visitied[i][j] = 0;
        }  
    }
}

// 이동방향에 칸이 있는지 확인(이동가능 여부)
bool check(int x, int y) {
    return x >= 1 && x <= M && y >= 1 && y <= N;
}

// 반대반향으로 회전
void rotate180() {
    D = (D + 2 > 3) ? (D+2)%4 : D + 2;
}
// 시계방향 90도 회전
void right() {
    D = (D + 1 > 3) ? 0 : D + 1;
}
// 반시계방향 90도 회전
void left() {
    D = (D - 1 < 0) ? 3 : D - 1;
}

int bfs(int startX, int startY){
    int value = num[startY][startX];
    int cnt = 1;
    visitied[startY][startX] = 1;
    q.push({startX, startY});

    while(!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && num[iy][ix] == value) {
                visitied[iy][ix] = 1;
                q.push({ix, iy});
                cnt++;
            }
        }
    }
    return cnt * value;
}

// 주사위 이동
void move() {
    for(int i = 0; i < 6; i++)
        tmp[i] = dice[diceRotate[D][i]];

    for(int i = 0; i < 6; i++)
        dice[i] = tmp[i];
}

// 주사위 게임 진행(주사위 굴러가기)
void playDice() {
    int ix = X + offer_X[D];
    int iy = Y + offer_Y[D];

    if(!check(ix, iy)) { // 이동방향에 칸이 없다면
        rotate180();
        ix = X + offer_X[D];
        iy = Y + offer_Y[D];
    }
    
    move();
    sum += bfs(ix, iy); // 점수획득

    // 이동방향 결정
    int A = dice[5];
    int B = num[iy][ix];
    if(A > B)
        right();
    else if(A < B)
        left();

    // 좌표 갱신    
    X = ix;
    Y = iy;
}

// 주사위 굴리기 2 
int main() {
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
            cin >> num[i][j];
        }  
    }
    // 처음 시작 셋팅
    X = 1;
    Y = 1;
    D = 0; // 동쪽을 바람보고있음

    while(0 < K--){
        playDice();
        init();
    }

    cout << sum << "\n";

    return 0;
}