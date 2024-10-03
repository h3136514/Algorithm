#include <iostream>
#include <queue>

using namespace std;
int R, C, K, a, b, sum, rocate, golemX, golemY, forest[75][75], isVisitied[75][75], isExited[75][75];
int offer_X[4] = {0, 1, 0, -1}; // 북, 동, 남, 서 
int offer_Y[4] = {-1, 0, 1, 0}; 
queue<pair<int, int>> q;


// 숲 초기화
void init() {
    for(int i = 0; i<= R + 2; i++) {
        for(int j = 1; j<= C; j++) {
            forest[i][j] = 0;
        }   
    }
}
// 출구 초기화
void init_distance() {
    //출구들 초기화
    for(int i = 0; i<= R + 2; i++) {
        for(int j = 1; j<= C; j++) {
            isExited[i][j] = 0;
        }   
    }

}

// 숲의 범위에 있는지
bool checkForest(int x, int y){
    return x > 0 && x <= C && y >= 3 && y <= R + 2; 
}

// 좌표 범위에 있는지 
bool check(int x, int y){
    return x > 1 && x < C  && y < R + 2; 
}

// 남쪽이동 체크
bool southCheck(int x, int y) {
    //정령위치
    int x1 = x;
    int y1 = y +1;
    //남쪽 체크
    int x2 = x1 +1;
    int y2 = y1;
    int x3 = x1 -1;
    int y3 = y1;
    int x4 = x1;
    int y4 = y1+1;
    

    if( y4 > R + 2)
        return false;

    return forest[y1][x1] == 0 && forest[y2][x2] == 0 && forest[y3][x3] == 0 && forest[y4][x4] == 0;
}

// 서쪽이동 체크
bool WestCheck(int x, int y) {
    //정령위치
    int x1 = x -1;
    int y1 = y;
    //서쪽 체크
    int x2 = x1;
    int y2 = y1-1;
    int x3 = x1-1;
    int y3 = y1;
    int x4 = x1;
    int y4 = y1+1;


    if(x3 < 1 || y4 > R + 2) // 범위밖
        return false;

    return forest[y1][x1] == 0 && forest[y2][x2] == 0 && forest[y3][x3] == 0 && forest[y4][x4] == 0;
}

// 동쪽이동 체크
bool EastCheck(int x, int y) {
    //정령위치
    int x1 = x +1;
    int y1 = y;
    //동쪽 체크
    int x2 = x1;
    int y2 = y1+1;
    int x3 = x1;
    int y3 = y1-1;
    int x4 = x1+1;
    int y4 = y1;


    if(x4 > C || y2 > R + 2) // 범위밖
        return false;

    return forest[y1][x1] == 0 && forest[y2][x2] == 0 && forest[y3][x3] == 0 && forest[y4][x4] == 0;
}

// 정령이 도달할 수 있는 최하단 행
int bfs(int x, int y) {
    for(int i = 0; i<= R + 2; i++) {
        for(int j = 1; j<= C; j++) {
            isVisitied[i][j] = 0;
        }   
    }
    int maxY = y;
    q.push({x, y});
    isVisitied[y][x] = 1;

    while(!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
        for(int i =0; i <4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            if(checkForest(ix, iy) && !isVisitied[iy][ix] && ((forest[currentY][currentX] == forest[iy][ix]) || (forest[iy][ix] != 0 && isExited[currentY][currentX])))
            {
                isVisitied[iy][ix] = 1;
                q.push({ix, iy});
                maxY = max(maxY, iy);
            }
        }
    }

    return maxY;

}

// 골램 진입
void play(int x, int d, int idx) {
    // 정령 좌표
    golemX = x;
    golemY = 1;
    rocate = d;

    while(true) {
        if(check(golemX, golemY+1) && southCheck(golemX, golemY)){
            golemY++;
        }else if(check(golemX-1, golemY+1) && WestCheck(golemX, golemY) && southCheck(golemX-1, golemY)){
            golemX--;
            golemY++;

            // 반시계 회전
            if(rocate == 0)
                rocate = 3;
            else
                rocate -= 1;
        }else if(check(golemX+1, golemY+1) && EastCheck(golemX, golemY)&& southCheck(golemX+1, golemY)) {
            golemX++;
            golemY++;

            // 시계 회전
            if(rocate == 3)
                rocate = 0;
            else
                rocate += 1;
        }else{  // 움직이질 못할 때
            break;
        }

        if(golemY + 1 >= R + 2)    // 끝에 도달
            break;
    }

    int xi = golemX;
    int yi = golemY;
    

    // 숲 밖에 있으면
    if(!checkForest(xi-1, yi-1) || !checkForest(xi+1, yi+1) )
    {   
        init();
        init_distance();
        return;
    }

    // 골렘이 숲 안에 정착
    forest[yi][xi] = idx;
    for(int i =0; i <4; i++)
        forest[yi + offer_Y[i]][xi + offer_X[i]] = idx;
    isExited[yi + offer_Y[rocate]][xi + offer_X[rocate]] = 1;

    // 탐색(정령 이동)
    int num = yi + 1;   // 남쪽 좌표
    if(num == R + 2){   // 최남단이라면
        sum+= num - 2;

        return;
    }
    num = bfs(xi, yi) - 2;

    return;
}

int main() {
    cin >> R >> C >> K;
    for(int i =1; i <= K; i++) {
        cin >> a >> b;

        play(a, b, i);
    }

    cout << sum << "\n";
    
    return 0;
}