#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, L, R, A[51][51], visited[51][51], r, c, sum, CNT, DAY;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
vector<pair<int, int>> v;   // 같은 연합 국가를 저장

// 방문 초기화
void init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            visited[i][j] = 0; 
        }
    }
}

// 유효한 좌표인지 확인
bool check(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

// 연합끼리 이동
void bfs(int startX, int startY) {
    sum = A[startY][startX];
    visited[startY][startX] = 1;
    q.push({startX, startY});
    v.push_back({startX, startY});

    // 연합 확인
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ix = x + offer_X[i];
            int iy = y + offer_Y[i];
            
            if(check(ix, iy) && !visited[iy][ix]){
                int differ = abs(A[y][x] - A[iy][ix]);
                
                if(differ >= L && differ <= R ) {
                    visited[iy][ix] = 1;    // 연합 국가 방문
                    q.push({ix, iy});
                    v.push_back({ix, iy});
                    sum += A[iy][ix];
                }
            }
        }

    }
    
    // 연합 인구수 재설정
    int n =v.size();
    CNT = max(CNT, n);  // 인구 이동 발생(연합 존재)
    int change = sum / v.size();
    
    for(int i = 0; i < n; i++) {
        int x = v[i].first;
        int y = v[i].second;
        A[y][x] = change;
    }
  
    v.clear();

}

// 국경 이동
void move() {
    DAY = -1; //인구 이동 날짜
    CNT = 2;
    while(CNT > 1) {
        CNT = 0;    // 하루에 인구이동 발생 횟수
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(!visited[i][j]) {
                    bfs(j, i);
                }        
            }
        }

        DAY++;  // 이동 날짜 증가

        init();
    }

}

// 인구 이동
int main() {
    cin >> N >> L >> R;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> A[i][j]; 
        }
    }

    move();
    cout << DAY << "\n";

    return 0;
}
