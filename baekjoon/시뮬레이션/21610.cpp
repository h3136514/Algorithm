#include <iostream>
#include <vector>

using namespace std;
int N, M, board[51][51], groomCheck[51][51];
int offer_X[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int offer_Y[8] = {0, -1, -1, -1, 0, 1, 1, 1};
vector<pair<int, int>> moveGroom, groom;

// 범위 확인
bool check(int x, int y) {
    return x > 0 && x <= N && y > 0 && y <= N;
}

// 구름 이동
void moveG(int d, int s) {
    for (int i = 0; i < groom.size(); i++) {
        int y = groom[i].first + offer_Y[d - 1] * ( s % N);
        int x = groom[i].second + offer_X[d - 1] * (s % N);
        
        if (x <= 0)
            x += N;
        else if (x > N)
            x -= N;

        if (y <= 0)
            y += N;
        else if (y > N)
            y -= N;

        groom[i].first = y;
        groom[i].second = x;
        groomCheck[y][x] = 1;   // 구름 표시
    }
}

// 구름 물의 양 증가
void rain() {
    for (int i = 0; i < groom.size(); i++) {
        board[groom[i].first][groom[i].second]++;
    }
}

// 물 복사 버그
void copyWater() {
    for(int i = 0; i < groom.size(); i++) {
        int y = groom[i].first;
        int x = groom[i].second;

        for (int j = 1; j <= 7; j += 2) {
            int iy = y + offer_Y[j];
            int ix = x + offer_X[j];
            if (check(ix, iy) && board[iy][ix]) {
                board[y][x]++;
            }
        }

    }
}

// 구름 추가
void addGroom() {
    groom.clear();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (groomCheck[i][j])
                groomCheck[i][j] = 0;
            else if (board[i][j] >= 2) {
                board[i][j] -= 2;

                groom.push_back({ i, j });
            }
        }
    }
}

// 현재 물의 총 양 출력
int pri() {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum += board[i][j];
        }
    }

    return sum;
}

// 마법사 상어와 비바라기
int main(){
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    moveGroom.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> moveGroom[i].first >> moveGroom[i].second;
    }

    // 초기 구름 투입
    for (int i = 1; i <= 2; i++) {
        groom.push_back({ N - 1, i });
        groom.push_back({ N, i });
    }

    // 명령 수행
    for (int i = 0; i < M; i++) {
        int d = moveGroom[i].first;
        int s = moveGroom[i].second;

        moveG(d, s);
        rain();
        copyWater();
        addGroom();
    }

    cout << pri() << "\n";

    return 0;
}