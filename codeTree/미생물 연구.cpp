#include <iostream>
#include <vector>
#include <queue>
#include <set> 
#include <map>
#include <algorithm>

using namespace std;
int N, Q, r1, c1, r2, c2, board[16][16], tmp[16][16], visitied[16][16], bioCnt[51], CNT, answer;
int offer_X[4] = { 1, 0, -1, 0 };
int offer_Y[4] = { 0, 1, 0, -1 };
map<int, pair<int, int>> smallLocat, bigLocat;
map<int, vector<pair<int, int>>> bio;
map<int, bool> bioLive;
queue<pair<int, int>> q;
priority_queue<pair<int, int>> startQ;
set<pair<int, int>> s;
vector<pair<int, int>> locat;

// 범위확인
bool check(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

// 초기화
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = 0;
            visitied[i][j] = 0;
        }
    }
}

void priLiv() {
    for (int i = 1; i <= CNT; i++) {
        cout << i << ":" << bioLive[i] << ", ";
    }
    cout << "\n";
}

// 최소, 최대 좌표
void changeSB(int num, vector<pair<int, int>> v) {
    int sx = 20, sy = 20, ex = -1, ey = -1;
    for (int i = 0; i < v.size(); i++) {
        sx = min(sx, v[i].first);
        sy = min(sy, v[i].second);
        ex = max(ex, v[i].first);
        ey = max(ey, v[i].second);
    }

    smallLocat[num] = { sx, sy };
    bigLocat[num] = { ex, ey };
}

// 현재 출력
void pri() {
    cout << CNT << ":\n";
    cout << "------------------------\n";
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "------------------------\n";
}

void pri2()
{
    cout << "------------------------\n";
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            cout << tmp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "------------------------\n";

}

// 미생물 분리 확인
int bfs(int num, int startX, int startY) {
    int cnt = 1;
    visitied[startY][startX] = 1;
    locat.push_back({ startX, startY });
    q.push({ startX, startY });

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if (check(ix, iy) && !visitied[iy][ix] && board[iy][ix] == num) {
                cnt++;
                visitied[iy][ix] = 1;
                locat.push_back({ ix, iy });
                q.push({ ix, iy });
            }
        }
    }

    return cnt;
}


// 미생물 좌표 갱신
void changeBioLocat(int num) {
    locat.clear();
    vector<pair<int, int>> v(bio[num]);
    int cnt = 0;

    for (int i = 0; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;

        if (num == board[y][x] && !visitied[y][x]) {
            cnt = bfs(num, x, y);   // 구역탐색시작
            if (cnt != bioCnt[num]) {
                //cout << "NO:" << num << " " << cnt << "!=" << bioCnt[num] << "\n";
                bioLive[num] = false;
            }
        }
    }

    // 미생물이 나누어져있을 때
    if (!bioLive[num]) {
        for (int i = 0; i < locat.size(); i++) {
            int x = locat[i].first;
            int y = locat[i].second;
            board[y][x] = 0;
        }
    }
    else {// 좌표갱신
        bio[num] = locat;

        changeSB(num, locat);
    }

}


// 미생물 투입
void movingBio() {
    set<int> meetBio;
    locat.clear();
    smallLocat[CNT] = { r1, c1 };
    bigLocat[CNT] = { r2 - 1, c2 - 1 };
    bioCnt[CNT] = (c2 - c1) * (r2 - r1);
    bioLive[CNT] = true;

    for (int i = c1; i < c2; i++) {
        for (int j = r1; j < r2; j++) {
            if (board[i][j]) {
                meetBio.insert(board[i][j]);
                bioCnt[board[i][j]]--;
            }

            locat.push_back({ j, i });
            board[i][j] = CNT;
        }
    }
    bio[CNT] = locat;

    // 만약 다른 미생물을 잡아먹었으면(좌표갱신)
    for (int num : meetBio) {
        if (bioCnt[num] == 0) {
            bioLive[num] = false;
        }
        else {
            changeBioLocat(num);
        }
    }

    meetBio.clear();
}

// 좌표 갱신
void reBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = tmp[i][j];
            tmp[i][j] = 0;
        }
    }
}

// 배양 용기 이동 가능 유무
bool checkMove(int num) {
    vector<pair<int, int>> v(bio[num]);
    int idxX = smallLocat[num].first;
    int idxY = smallLocat[num].second;

    int startX = 0, startY = 0, endX = bigLocat[num].first - smallLocat[num].first, endY = bigLocat[num].second - smallLocat[num].second;
    bool checkM = false;
    while (endX < N) {
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            int x = startX - idxX + v[i].first;
            int y = startY - idxY + v[i].second;
            if (tmp[y][x] == 0) {
                cnt++;
            }

        }

        if (cnt == bioCnt[num]) {
            checkM = true;
            break;
        }


        if (endY == N - 1) {
            startY = 0;
            endY = bigLocat[num].second - smallLocat[num].second;
            startX++;
            endX++;
        }
        else {
            startY++;
            endY++;
        }
    }

    vector<pair<int, int>> tmpV;
    if (checkM) {
        for (int i = 0; i < v.size(); i++) {
            int x = startX - idxX + v[i].first;
            int y = startY - idxY + v[i].second;
            tmp[y][x] = num;

            tmpV.push_back({ x, y });
        }



        changeSB(num, tmpV);
        bio[num] = tmpV;
    }

    v.clear();
    tmpV.clear();

    return checkM;
}



//배양 용기 이동
void moveBioBoard() {
    // 순서 정하기
    for (int i = 1; i <= CNT; i++) {
        if (bioLive[i]) {
            startQ.push({ bioCnt[i], -i });
        }
    }

    while (!startQ.empty()) {
        int num = -startQ.top().second;
        startQ.pop();
       // cout << num << "..";
        if (!checkMove(num)) {
            bioLive[num] = false;
        }

    }
   
    reBoard();
}

void bfsResult(int num, int startX, int startY) {
    visitied[startY][startX] = 1;
    q.push({ startX, startY });

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if (check(ix, iy) && board[iy][ix] != num && board[iy][ix] != 0) {
                if (num < board[iy][ix])
                    s.insert({ num, board[iy][ix] });
                else
                    s.insert({ board[iy][ix], num });
            }

            if (check(ix, iy) && !visitied[iy][ix] && board[iy][ix] == num) {
                visitied[iy][ix] = 1;
                q.push({ ix, iy });
            }
        }
    }

}

// 결과기록
void result() {
    init();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visitied[i][j] && board[i][j]) {
                bfsResult(board[i][j], j, i);
            }
        }
    }

    for (auto target : s) {
        answer += (bioCnt[target.first] * bioCnt[target.second]);
    }

    s.clear();
}

void proS() {
    cout << "00000000000000000\n";
    for (int i = 1; i <= CNT; i++) {
        cout << i << ":" << bioCnt[i] << "\n";
    }
    cout << "00000000000000000\n";
}


int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        CNT = i;
        answer = 0;

        movingBio();
        //pri();
        init();
        //priLiv();

        moveBioBoard();
        //pri();
        //priLiv();

        result();
        //proS();

        cout << answer << "\n";
        init();
    }

    return 0;
}
