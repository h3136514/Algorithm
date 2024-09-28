#include <iostream>
#include <queue>

using namespace std;
int N, shark, sharkX, sharkY, eat, CNT, num[21][21], visitied[21][21];
int offer_X[4] = {0, -1, 1, 0};
int offer_Y[4] = {1, 0, 0, -1};
queue<pair<int, pair<int, int>>> q; // bfs 사용 큐
priority_queue<pair<int, pair<int, int>>> eats; // 먹을 수 있는 물고기들 

// 방문 초기화
void init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visitied[i][j] = 0;
        }
    }

    while(!eats.empty())
        eats.pop();
}

// 범위 체크
bool check(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// 상어 크기 체크
void sharkSize() {
    if(shark == eat){
        shark++;
        eat = 0;    // 먹은 물고기 초기화
    }
}

// 아기 상어 식사(삭사 했으면 : true, 삭사 못했으면 : false)
int bfs() {
    int cnt = 0;
    q.push({cnt, {sharkX, sharkY}});
    visitied[sharkY][sharkX] = 1;

    while(!q.empty()) {
        int currentCnt = q.front().first;
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            int icnt = currentCnt + 1;

            if(check(ix, iy) && !visitied[iy][ix]) {
                if(num[iy][ix] > shark)
                    continue;
                
                if(num[iy][ix] < shark && num[iy][ix] != 0) {   //먹을 수 있는 경우
                    eats.push({-icnt, {iy, -ix}});  // 먹음(이동거리가 최소, 가장 위에(y증가), 가장 왼쪽(x감소)의 우선순위를 가지고 있어서)
                }else {
                    q.push({icnt, {ix, iy}}); // 이동
                }

                visitied[iy][ix] = 1;
            }
        }
    }

    if(eats.size() == 0)
        return false;
    
    int currentCnt = -eats.top().first;
    int currentY = eats.top().second.first;
    int currentX = -eats.top().second.second;

    CNT += currentCnt;  //거리 더함(이동한 횟수 = 시간)
    
    num[sharkY][sharkX] = 0;
    num[currentY][currentX] = 9;
    sharkX = currentX;
    sharkY = currentY;
    eat++;

    return true;
}

// 아기 상어 
int main() {
    cin >> N;
    for(int i = N-1; i >= 0; i--) {
        for(int j = 0; j < N; j++) {
            cin >> num[i][j];
            if(num[i][j] == 9) {
                sharkX = j;
                sharkY = i;
            }
        }
    }

    shark = 2;  // 아기 상어 처음 크기
    while(true) {
        bool checkEat = bfs();
        if(!checkEat) // 더 이상 먹을게 없으면 => 탈출
            break;
        
        sharkSize();   //상어 크기 체크
        init();
    }

    cout << CNT << "\n";

    return 0;
}
