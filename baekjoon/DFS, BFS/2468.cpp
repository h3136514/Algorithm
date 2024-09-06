#include <iostream>

#define MAX 101
using namespace std;
int N, num[MAX][MAX], visitied[MAX][MAX], cnt, max_cnt, max_h;
int offerset_X[4] = {-1, 1, 0, 0};
int offerset_Y[4] = {0, 0, -1, 1};

// 유효한 위치 확인
bool check(int x, int y) {
    return x >=0 && y >=0 && x < N && y <N;
}

void dfs(int x, int y, int h) {
    if(visitied[y][x])
        return;
    
    visitied[y][x] = 1;
    for(int i = 0; i < 4; i++) {
        int ix = x + offerset_X[i];
        int iy = y + offerset_Y[i];

        if(check(ix, iy) && num[iy][ix] > h) {
            dfs(ix, iy, h);
        }
    }
}

// 방문 초기화
void init() {
    cnt = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visitied[i][j] = 0;
        }
    }
}
int main() {
    max_h = 0;
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> num[i][j];
            if(max_h < num[i][j])
                max_h = num[i][j];
        }
    }

    // 최대 높이까지 물잠김 확인
    for(int h = 0; h < max_h; h++) {

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visitied[i][j] && num[i][j] > h){
                    cnt++;
                    dfs(j, i, h);
                }
            }
        }

        if(max_cnt < cnt)
            max_cnt = cnt;

        init();
    } 

    cout << max_cnt << "\n";

    return 0;
}