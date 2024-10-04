// DFS
#include <iostream>

using namespace std;
int R, C, CNT, visitied[26]; // 알파벳 순서대로 방문체크
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
char alp[21][21];

// 범위체크
bool check(int x, int y) {
    return x >= 0 && x < C && y >= 0 && y < R;
}

// dfs(백트래킹)
void dfs(int x, int y, int cnt) {
    CNT = max(CNT, cnt);

    for(int i = 0; i < 4; i++) {
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];
        if(!check(ix, iy))
            continue;

        int num2 = int(alp[iy][ix]) - 65;
        if(visitied[num2])
            continue;
            
        visitied[num2] = 1;
        dfs(ix, iy, cnt+1);
        visitied[num2] = 0;
        
    }

}

// 알파벳 (좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지구하라 단, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.)
int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> alp[i][j];
        }
    }
    int num = int(alp[0][0]) - 65;
    visitied[num] = 1;  // 시작점 방문 설정

    dfs(0, 0, 1);

    cout << CNT << "\n";
    return 0;
}