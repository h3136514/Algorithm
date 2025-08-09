#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int N, M, D, board[16][16], gameBoard[16][16], result;
vector<pair<int, int>> archer, enemy;
priority_queue<pair<int, pair<int, int>>> q;

// 게임 초기화
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            gameBoard[i][j] = board[i][j];
            if (gameBoard[i][j] == 1)
                enemy.push_back({ j, i });
        }
    }
}

// 적이동
void moveEnemy() {
    enemy.clear();
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (gameBoard[i][j] == 1) {
                gameBoard[i][j] = 0;
                if(i == N - 1)
                    continue;

                gameBoard[i + 1][j] = 1;
                enemy.push_back({ j, i + 1 });
            }
        }
    }
}

// 게임 시작
void game(vector<pair<int, int>> v){
    init();
    int cnt = 0;
    while (true) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < enemy.size(); j++) {
                int dist = abs(v[i].first - enemy[j].first) + abs(v[i].second - enemy[j].second);

                q.push({ -dist, {v[i].first - enemy[j].first, j} }); // 가장 가까우면서도 왼쪽에 있는 적
            }

            if (-q.top().first <= D) {
                int x = enemy[q.top().second.second].first;
                int y = enemy[q.top().second.second].second;

                if (gameBoard[y][x]) {
                    gameBoard[y][x] = 0;
                    cnt++;
                }
            }

            while (!q.empty())
                q.pop();
        }

        moveEnemy();

        if (enemy.empty())  // 모든 적이 격자판에서 제외되면
            break;
    }
   
    result = max(result, cnt);
}


// 궁수 배치(모든 경우의 수)
void archerBatch(int idx, vector<pair<int, int>> v) {
    if (v.size() == 3) {
        game(v);
        return;
    }

    for (int i = idx; i < M; i++) {
        vector<pair<int, int>> tmp = v;
        tmp.push_back({ i, N });
        archerBatch(i + 1, tmp);
    }
}



// 캐슬 디펜스
int main() {
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    vector<pair<int, int>> v;
    archerBatch(0,  v);

    cout << result << "\n";

    return 0;
}