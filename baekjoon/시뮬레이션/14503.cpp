#include <iostream>

using namespace std;
int N, M, r, c, d, num[51][51], CNT;
int offer_X[4] = {0, 1, 0, -1};
int offer_Y[4] = {-1, 0, 1, 0};

// 90 회전
void rocate() {
    if(d == 0)
        d = 3;
    else
        d -=1;
}

// 주변 4칸 중 청소되지 않은 빈 칸 유무
bool checkClean(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];

        if(num[iy][ix] == 0)
            return true;
    }

    return false;
}

// 후진 할 수 있는지(할 수 있으면 후진)
bool checkBack(int x, int y) {
    int backD = 0;
    if(d >= 2)
        backD = d - 2;
    else
        backD = d + 2;
    
    // 후진 했을 때 좌표 값
    int ix = x + offer_X[backD];
    int iy = y + offer_Y[backD];
    
    // 벽이면(후진 X)
    if(num[iy][ix] == 1)
        return false;

    c = ix;
    r = iy;

    return true;
}


void clean() {
    while(true) {
        if(!num[r][c]) {
            num[r][c] = 2;  // 2: 청소함
            CNT++;
        }
        
        if(checkClean(c, r)) {
            rocate();
            // 앞쪽 한칸
            int ix = c + offer_X[d];
            int iy = r + offer_Y[d];
            if(!num[iy][ix]) {  // 청소되지 않았으면 전진
                c = ix;
                r = iy;
            }
            
            continue;

        }else {
            if(checkBack(c, r)) //후진유무
                continue;
            else
                break;
        }
        
    }
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> d;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> num[i][j];
        }
    }

    clean();
    cout << CNT << "\n";

    return 0;
}