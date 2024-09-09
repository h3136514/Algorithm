#include <iostream>
#include <queue>

#define MAX 101
using namespace std;
int M, N, K, x1, y1, x2, y2, CNT, paper[MAX][MAX], visitied[MAX][MAX];
int offerset_X[4] = {-1, 1, 0, 0};
int offerset_Y[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;
priority_queue<int> result;

bool check(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

int bfs(int startX, int startY) {
    int cnt = 1;
    visitied[startY][startX] = 1;
    q.push({startX, startY});

    while(!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
    
        for(int i = 0; i <4; i++) {
            int iX = currentX + offerset_X[i];
            int iY = currentY + offerset_Y[i];

            if(check(iX, iY) && !paper[iY][iX] && !visitied[iY][iX]) {
                cnt++;
                visitied[iY][iX] = 1;
                q.push({iX, iY});
            }
        }
    }

    return cnt;
}


// 눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 분리되어 나누어지는 영역의 개수, 각 영역의 넓이를 오름차순으로 정렬하여 출력한다.
int main() {
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int j = y1; j < y2; j++) {
            for(int k = x1; k < x2; k++) {
                paper[j][k] = 1;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(!paper[i][j] && !visitied[i][j]) {
                CNT++;
                int sum = bfs(j, i);
                
                result.push(-sum);
            }
        }
    }

    cout << CNT << "\n";
    while(!result.empty()) {
        cout << -result.top() << " ";
        result.pop();
    }
    
    return 0;
}