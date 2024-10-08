#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M, Rx, Ry, Bx, By, visited[11][11][11][11];  //빨간공 & 파란공 방문체크
int offer_X[4] = { 1, 0, -1, 0 };
int offer_Y[4] = { 0, 1, 0, -1 };
char board[11][11];
queue<vector<int>> q;
vector<int> tmpV;

// 이동
void move(int& rcnt, int& bcnt, int& r, int& rx, int& ry, int& bx, int& by) {
    // 빨간 공 이동
    while(board[ry+offer_Y[r]][rx+offer_X[r]] != '#' && board[ry][rx] != 'O' ){ // 벽이면X, 도착하면 나가기
        rx += offer_X[r];
        ry += offer_Y[r];   
        rcnt++;
    }

    // 파란 공 이동
    while(board[by+offer_Y[r]][bx+offer_X[r]] != '#' && board[by][bx] != 'O' ){ // 벽이면X, 도착하면 나가기
        bx += offer_X[r];
        by += offer_Y[r];
        bcnt++;
    }
}

// bfs (기울이기)
void bfs() {
    vector<int> v = {0,  Rx, Ry, Bx, By}; // 횟수, 좌표
    visited[Ry][Rx][By][Bx] = 1;
    q.push(v);

    while (!q.empty()) {
        vector<int> currentV = q.front();
        q.pop();
        int cnt = currentV[0];
        int rx = currentV[1];
        int ry = currentV[2];
        int bx = currentV[3];
        int by = currentV[4];
       
        if (cnt >= 10)
            break;

        for (int i = 0; i < 4; i++) {
            int ix1 = rx;
            int iy1 = ry;
            int ix2 = bx;
            int iy2 = by;
            int rcnt = 0;
            int bcnt = 0;
            
            move(rcnt, bcnt, i, ix1, iy1, ix2, iy2); // 이동해보기(기울여보기)
        
            if(board[iy2][ix2] =='O') // 파란공이 먼저 오는경우
                continue;
            if(board[iy1][ix1] =='O'){ // 빨간 공만 오는경우
                cout << cnt+1 << "\n";
                return;
            }

            // 둘다 같은 곳에 도착 했으면
            if(iy1 == iy2 && ix1 == ix2){
                if(rcnt > bcnt){    // 더 많이 이동한 공을 한칸 뒤로 이동
                    ix1 -= offer_X[i];
                    iy1 -= offer_Y[i];
                }else{
                    ix2 -= offer_X[i];
                    iy2 -= offer_Y[i];
                }
            }

            if (!visited[iy1][ix1][iy2][ix2]){
                visited[iy1][ix1][iy2][ix2] = 1;
                //큐에 삽입
                tmpV.push_back(cnt+1);
                tmpV.push_back(ix1);
                tmpV.push_back(iy1);
                tmpV.push_back(ix2);
                tmpV.push_back(iy2);
                q.push(tmpV);
                tmpV.clear();
            }

        }
       
    }

    cout << -1 << "\n";
}

// 구슬 탈출 2
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                Rx = j;
                Ry = i;
            }
            if (board[i][j] == 'B') {
                Bx = j;
                By = i;
            }
        }
    }

    bfs();

    return 0;
}