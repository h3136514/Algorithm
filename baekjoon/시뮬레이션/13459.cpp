#include <iostream>
#include <queue>

using namespace std;
int N, M, visitied[11][11][11][11], Rx, Ry, Bx, By, result = 0;
int offer_X[4] = {1, -1, 0, 0};
int offer_Y[4] = {0, 0, 1, -1};
char board[11][11];
queue<vector<int>> q;

// 이동
void move(int& rx, int& ry, int& bx, int& by, int& rcnt, int& bcnt, int d){
    // 빨간공 이동
    while(board[ry+offer_Y[d]][rx + offer_X[d]] != '#' && board[ry][rx] != 'O'){
        ry += offer_Y[d];
        rx += offer_X[d];

        rcnt++;
    }

    // 파란공 이동
    while(board[by+offer_Y[d]][bx + offer_X[d]] != '#' && board[by][bx] != 'O'){
        by += offer_Y[d];
        bx += offer_X[d];

        bcnt++;
    }
}

void bfs(){
    visitied[Ry][Rx][By][Bx] = 1;
    q.push({0, Rx, Ry, Bx, By});

    while(!q.empty()){
        vector<int> v(q.front());
        q.pop();
        int currentCnt = v[0];
        int rx = v[1];
        int ry = v[2];
        int bx = v[3];
        int by = v[4];

        if(currentCnt >= 10)
            break;
        
        for(int i = 0; i < 4; i++){
            int icnt = currentCnt + 1;
            int rcnt = 0, bcnt = 0; // 겹쳤을 때를 구분하기 위해
            int irx = rx, iry = ry, ibx = bx, iby = by;

            move(irx, iry, ibx, iby, rcnt, bcnt, i);
            
            if(board[iby][ibx] == 'O')   // 동시에 빠지거나, 파란 공이 먼저 빠짐
                continue;
            if(board[iry][irx] == 'O'){   // 빨간 공이 먼저 빠짐
                result = 1;
                return;
            }

            if((irx == ibx) && (iry == iby)){   // 같은 좌표에 있을 때(겹침)
                if(rcnt < bcnt){    // 파란공 한칸 뒤로가기
                    ibx -= offer_X[i];
                    iby -= offer_Y[i];
                }else{// 빨간 공 한칸 뒤로가기
                    irx -= offer_X[i];
                    iry -= offer_Y[i];
                }
            }

            if(!visitied[iry][irx][iby][ibx]){
                visitied[iry][irx][iby][ibx] = 1;
                q.push({icnt, irx, iry, ibx, iby});
            }
            
        }

    }

}

// 구슬 탈출
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            if(board[i][j] == 'R'){
                Ry = i;
                Rx = j;
            }

            if(board[i][j] == 'B'){
                By = i;
                Bx = j;
            }
        }
    }

    bfs();

    cout << result << "\n";

    return 0;
}