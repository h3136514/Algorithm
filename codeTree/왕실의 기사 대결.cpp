#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int L, N, Q, r, c, h, w, k, n, d, damage[31], health[31], die[31], moves[31], board[43][43], knithBoard[43][43], visitied[43][43], sum;
int offer_X[4] = { 0, 1, 0, -1 };
int offer_Y[4] = { -1, 0, 1, 0 };
vector<int> V[31];
queue<pair<int, int>> q;
vector<int> close;

/*
void printBoard() {
    cout << "-----------\n";
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cout << knithBoard[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-----------\n";
}
void printB() {
    cout << "-----------\n";
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-----------\n";
}

void printDeath() {
    cout << "-----------\n";
    for (int i = 1; i <= N; i++)
        cout << die[i] << " ";

    cout << "-----------\n";
}

void printV() {
    cout << "-----------\n";
    for (int i = 1; i <= N; i++)
        cout << V[i][0] <<","<<V[i][1] << " ";

    cout << "-----------\n";
}

void printDamage() {
    cout << "-----------\n";
    for (int i = 1; i <= N; i++)
        cout << damage[i] << " ";

    cout << "-----------\n";
}
*/

// 초기화
void init() {
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            visitied[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++)
        moves[i] = 0;

    close.clear();
}

//범위 확인
bool check(int x, int y) {
    return x >= 1 && x <= L && y >= 1 && y <= L;
}

//번호 체크
bool checkKnith(int num) {
    return  num >= 1 && num <= N;
}

// 이동 가능 확인
bool moveCheck(int num, int dir) {
    int x, y, xe, ye;
    x = V[num][0] + offer_X[dir];
    y = V[num][1] + offer_Y[dir];
    xe = x + V[num][3];
    ye = y + V[num][2];

    if (!check(x, y)||!check(xe - 1, ye - 1))
        return false;

    for (int i = y; i < ye; i++) {
        for (int j = x; j < xe; j++) {
            if (board[i][j] == 2) {
                return false;
            }
        }
    }

    return true;
}

// 함정 계산
void trackCal(int num) {
    int x, y, xe, ye;
    x = V[num][0];
    y = V[num][1];
    xe = x + V[num][3];
    ye = y + V[num][2];

    if (!check(x, y) || !check(xe - 1, ye - 1))
        return;

    for (int i = y; i < ye; i++) {
        for (int j = x; j < xe; j++) {
            if (board[i][j] == 1)
                damage[num]++;
        }
    }
}

// 이동
void move(int num, int dir) {
    int x, y, xe, ye;
    // 원래 있더 자리 정리
    x = V[num][0];
    y = V[num][1];
    xe = x + V[num][3];
    ye = y + V[num][2];

    for (int i = y; i < ye; i++) {
        for (int j = x; j < xe; j++) {
            if (knithBoard[i][j] == num)
                knithBoard[i][j] = 0;
        }
    }

    // 다음에 옮길 자리 이동
    x = V[num][0] + offer_X[dir];
    y = V[num][1] + offer_Y[dir];
    xe = x + V[num][3];
    ye = y + V[num][2];

    for (int i = y; i < ye; i++) {
        for (int j = x; j < xe; j++) {
            knithBoard[i][j] = num;
        }
    }

    V[num][0] = x;
    V[num][1] = y;

}

// 죽었는지 확인 및 조치
void deathCheck() {
    int x, y, xe, ye;
    for (int i = 1; i <= N; i++) {
        if (!die[i] && (health[i] <= damage[i])) {
            die[i] = 1;
            // 원래 있더 자리 정리
            x = V[i][0];
            y = V[i][1];
            xe = x + V[i][3];
            ye = y + V[i][2];

            for (int i = y; i < ye; i++) {
                for (int j = x; j < xe; j++) {
                    knithBoard[i][j] = 0;
                }
            }

        }
    }
}


// bfs (이동하는 방향에 다른 기사가 있는지 탐색)
void bfs(int num, int dir) {
    int x, y;
    x = V[num][0];
    y = V[num][1];
    q.push({ x,y });
    visitied[y][x] = 1;

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        int idx = knithBoard[currentY][currentX];

        q.pop();

        if (checkKnith(idx) && !moves[idx]) { // 중복 방지
            moves[idx] = 1;
            close.push_back(idx);
        }

        for (int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if (check(ix, iy) && !visitied[iy][ix]) {
                if ((i == dir && idx != knithBoard[iy][ix] && knithBoard[iy][ix] != 0) || (idx == knithBoard[iy][ix])) {
                    q.push({ ix, iy });
                    visitied[iy][ix] = 1;
                }
            }
        }
    }

}

int main() {
    cin >> L >> N >> Q;
    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= L; j++) {
            cin >> board[i][j];
        }
    }
    // 양쪽 끝을 벽으로
    for (int i = 0; i <= L + 1; i++) {
        board[i][0] = 2;
        board[0][i] = 2;
        board[L + 1][0] = 2;
        board[0][L + 1] = 2;
    }

    for (int i = 1; i <= N; i++) {
        cin >> r >> c >> h >> w >> k;
        V[i].push_back(c);
        V[i].push_back(r);
        V[i].push_back(h);
        V[i].push_back(w);
        health[i] = k;

        for (int j = r; j < r + h; j++) {
            for (int l = c; l < c + w; l++) {
                knithBoard[j][l] = i;
            }
        }
    }

    while (Q--) {
        cin >> n >> d;
        if (die[n]) // 이미 사라진 기사는 명령 못받음
            continue;

        bfs(n, d);

        // 이동 가능 확인
        bool moveCheckTrue = true;

        for (int i = 0; i < close.size(); i++) {
            int num = close[i];
            //cout << num << "-\n";
            if (!moveCheck(num, d)) {
                moveCheckTrue = false;
            
                break;
            }
        }
    

        // 이동 하기
        if (moveCheckTrue) {
            for (int i = 0; i < close.size(); i++) {
                int num = close[i];
                move(num, d);
                if (n != num) // 자기 자신은 데미지X
                    trackCal(num);
            }

        }

        deathCheck();
        init();
     
    }

    for (int i = 1; i <= N; i++) {
        if (!die[i])
            sum += damage[i];
    }

    cout << sum << "\n";

    return 0;
}