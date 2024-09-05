#include <iostream>

using namespace std;
int W, H, cnt, land[51][51], visitied[51][51];
int offerset_X[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int offerset_Y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

//초기화
void init() {
    cnt = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            land[i][j] = 0;
            visitied[i][j] = 0;
        }
    }
}

// 유효한 좌표인지 체크
bool check(int x, int y) {
    return x >= 0 && y >= 0;
}

void dfs(int x, int y) {
    if(visitied[y][x])
        return;
    
    visitied[y][x] = 1;
    for(int i = 0; i < 8; i++) {
        int ix = x + offerset_X[i];
        int iy = y + offerset_Y[i];

        //연결된 섬들 다 방문
        if(check(x,y) && land[iy][ix])
            dfs(ix, iy);
    }

}

// 섬의 개수를 세는 프로그램(땅이 이어져 있으면 섬)
int main() {
    while(true) {
        cin >> W >> H;
        if(W==0 && H==0)
            break;

        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> land[i][j];
            }
        }

        // 연결된 섬 탐색
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                //아직 방문하지 않은 땅 DFS탐색
                if(!visitied[i][j] && land[i][j]){
                    dfs(j, i);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
        init();

    }


    return 0;
}