#include <iostream>
#include <queue>

using namespace std;
int N, M, K, board[11][11], attacked[11][11], close[11][11], visitied[11][11], attackX, attackY, cannonCNT, CNT;
int offer_X[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
int offer_Y[8] = { 0, 1,  0, -1, -1, 1, 1, -1 };
priority_queue<pair<pair<pair<int, int>, int>, pair<int, int>>>q1, q2;
queue<pair< pair<int, int>, vector<pair<int, int>>>> q;
vector<pair<int, int>> V;

void printZ() {
    cout << "--------------------------\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "--------------------------\n";
}

void init() {
for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        visitied[i][j] = 0;
    }
}

while (!q1.empty())
q1.pop();
while (!q2.empty())
q2.pop();
while (!q.empty())
q.pop();
}

bool check(int x, int y) {
    return x >= 0 && x < M && y >= 0 && y < N;
}

void changeXY(int& x, int& y) {
    if (x < 0)
        x = M - 1;
    if (x >= M)
        x = 0;
    if (y < 0)
        y = N - 1;
    if (y >= N)
        y = 0;
}

void attack(int c) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != 0) {
                q1.push({ {{-board[i][j] , attacked[i][j]}, i + j},{j, i} });
            }
        }
    }

    attackY = q1.top().second.second;
    attackX = q1.top().second.first;

    attacked[attackY][attackX] = c;
    close[attackY][attackX] = c;

    board[attackY][attackX] += N + M;
}

bool bfs(int targetX, int targetY) {
    visitied[attackY][attackX] = 1;
    vector<pair<int, int>> v;
    q.push({ {attackX, attackY}, v });

    while (!q.empty()) {
        int currentX = q.front().first.first;
        int currentY = q.front().first.second;
        vector<pair<int, int>> cv = q.front().second;
        q.pop();

        if (currentX == targetX && currentY == targetY) {
            V = cv;

            return true;
        }

        for (int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if (!check(ix, iy))
                changeXY(ix, iy);

            if (!visitied[iy][ix] && board[iy][ix] != 0) {
                visitied[iy][ix] = 1;
                cv.push_back({ ix, iy });
                q.push({ {ix, iy}, cv });
                //cout << cv.size() << "\n";
                cv.pop_back();
            }
        }
    }

    return false;
}

void attackStart(int c) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != 0 && (attackX != j || attackY != i)) {
                q2.push({ {{board[i][j] , -attacked[i][j]}, -(i + j)},{-j, -i} });
            }
        }
    }
    int targetY = -q2.top().second.second;
    int targetX = -q2.top().second.first;
    //close[targetY][targetX] = c;

    //cout << "target:"<< targetX << targetY << "\n";
    //cout << "attack:" << attackX << attackY << "\n";
    if (bfs(targetX, targetY)) {    //레이저 공격 성공
       // cout << "rager \n";
        //cout << V.size() <<" \n";
        for (int i = 0; i < V.size(); i++) {
            int x = V[i].first;
            int y = V[i].second;

            if (targetX == x && targetY == y) {
                close[y][x] = c;
                board[y][x] -= board[attackY][attackX];
                if(board[y][x] <= 0) {
                    board[y][x] = 0;
                    cannonCNT--;
                }
                continue;
            }

            if (attackX != x || attackY != y){
                close[y][x] = c;
                board[y][x] -= board[attackY][attackX] / 2;
                if (board[y][x] <= 0) {
                    board[y][x] = 0;
                    cannonCNT--;
                }
            }
        }

        V.clear();

    }
    else {  // 포탄 공격
        //cout << "cannon \n";
        close[targetY][targetX] = c;
        board[targetY][targetX] -= board[attackY][attackX];
        if (board[targetY][targetX] <= 0) {
            board[targetY][targetX] = 0;
            cannonCNT--;
        }

        for (int i = 0; i < 8; i++) {
            int ix = targetX + offer_X[i];
            int iy = targetY + offer_Y[i];

            if (!check(ix, iy))
                changeXY(ix, iy);
            
            if(ix == attackX && iy == attackY)
                continue;

            if (board[iy][ix] != 0) {
                close[iy][ix] = c;
                board[iy][ix] -= board[attackY][attackX] / 2;
                if (board[iy][ix] <= 0) {
                    board[iy][ix] = 0;
                    cannonCNT--;
                }
            }
        }

    }

}

// 포탑 정비
void health(int c) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != 0 && close[i][j] != c) {
                board[i][j]++;
            }
        }
   
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] != 0)
                cannonCNT++;
        }
    }

    for (int i = 1; i <= K; i++) {
        attack(i);
        attackStart(i);
        if (cannonCNT <= 1)
            break;

        health(i);
        //printZ();
        init();


    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] != 0) {
                CNT = max(CNT, board[i][j]);
            }
        }
    }

    cout << CNT << "\n";

    return 0;
}
