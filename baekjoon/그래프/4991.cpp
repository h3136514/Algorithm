#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define INF 987654321
using namespace std;
int w, h, num, visitied[20][20], targetX, targetY, CNT;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
string room[20];
queue<pair<pair<int, int>, int>> q;
vector<pair<int, int>> v;

bool check(int x, int y){
    if(room[y][x] == 'x')
        return false;
    
    return x >= 0 && x < w && y >= 0 && y < h;
}

void init(){
    CNT = INF;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            visitied[i][j] = 0;
        }
    }
}

void bfs(int startX, int startY, int endX, int endY){
    visitied[startY][startX] = 1;
    q.push({{startX, startY},  0});

    while(!q.empty()){
        int currentX = q.front().first.first;
        int currentY = q.front().first.second;
        int currentDist = q.front().second.first;
        int currentCnt = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            int icnt = currentDist + 1;

            if(check(ix, iy) && )
        }
    }
}

int main(){
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0)
            break;
        for(int i = 0; i < h; i++){
            cin >> room[i];
        }

        // 시작위치 찾기
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(room[i][j] == 'o'){
                    targetX = j, targetY = i;
                    break;
                }
            }
        }

        init();


    }

    return 0;
}