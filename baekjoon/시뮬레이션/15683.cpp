#include <iostream>
#include <vector>

#define MAX_VALUE  987654321
using namespace std;
int N, M, num, cctvSize, minSum = MAX_VALUE;
int offer_X[4] = {0, -1, 0, 1};
int offer_Y[4] = {1, 0, -1, 0};
int office[8][8]; // 사무실 공간
vector<pair<int,int>> cctv;  // CCTV 위치 저장

// CCTV 관찰
void observe(int x, int y, int r) {
    r %= 4;
    
    while(true){
        int ix = x + offer_X[r];
        int iy = y + offer_Y[r];
        x= ix;
        y= iy;
    
        if(ix < 0 || ix >= M || iy < 0 || iy >= N)
            return;
    
        if(office[iy][ix] == 6)
            return;

        if(office[iy][ix] != 0)
            continue;
        
        office[iy][ix] = 10;

    }
}

void dfs(int cnt) {
    if(cnt == cctvSize) {
        int sum = 0;
        //사각 지대 계산
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(office[i][j] == 0)
                    sum++;
            } 
        }
        
        minSum = min(minSum, sum);
        return;
    }

    int x = cctv[cnt].first;
    int y = cctv[cnt].second;
    int cctvValue = office[y][x];

    int tmp[9][9];  // 임시 저장소
    for(int i = 0; i < 4; i++) {
        // 임시 저장
         for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                tmp[i][j] = office[i][j];

        if(cctvValue == 1)  // 한쪽만 확인(모든 방향 확인)
            observe(x, y, i);  
        else if(cctvValue == 2) {   // 양 방향 확인(위아래, 오른쪽왼쪽)
            observe(x, y, i);       
            observe(x, y, i + 2);
        }else if(cctvValue == 3) {  // x, y같이 확인(왼쪽위, 위오른쪽, 오른쪽아래, 아래왼쪽 확인)
            observe(x, y, i);
            observe(x, y, i + 1);
        }else if(cctvValue == 4) {  // 한번에 세방향 확인  
            observe(x, y, i);
            observe(x, y, i + 1);
            observe(x, y, i + 2);
        }else if(cctvValue == 5) {  // 한번에 모든방향 확인  
            observe(x, y, i);
            observe(x, y, i + 1);
            observe(x, y, i + 2);
            observe(x, y, i + 3);
        }

        dfs(cnt + 1);

        // 다시 초기화
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                office[i][j] = tmp[i][j];

    }
    
}

// 감시
int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> office[i][j];
            //cctv 저장
            if(office[i][j] != 0 && office[i][j] != 6)
                cctv.push_back({j, i});
        }
    }

    cctvSize = cctv.size();
    dfs(0);

    cout << minSum << "\n";

    return 0;
}