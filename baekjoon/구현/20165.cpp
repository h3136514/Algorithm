#include <iostream>
#include <map>

using namespace std;
int N, M, R, X, Y, board[101][101], visitied[101][101], result = 0;
int offer_X[4] = {1, -1, 0, 0};
int offer_Y[4] = {0, 0, 1, -1};
char D;
map<char, int> m;

// 범위 확인
bool check(int x, int y){
    return x > 0 && x <= M && y > 0 && y <= N;
}

// 결과 출력
void pri(){
    cout << result << "\n";
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            char c = (visitied[i][j]) ? 'F' : 'S'; 
            cout << c << " ";
        }
        cout << "\n";
    }
}

// 인내의 도미노 장인 호석
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    m['E'] = 0, m['W'] = 1, m['S'] = 2, m['N'] = 3;

    cin >> N >> M >> R;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> board[i][j];
        }
    }

    while(R--){
        int cnt = 0;
        cin >> Y >> X >> D;

        if(!visitied[Y][X]){
            int id = m[D];
            visitied[Y][X] = 1;
            cnt++;
            int targetX = X + (offer_X[id] * (board[Y][X]-1));
            int targetY = Y + (offer_Y[id] * (board[Y][X]-1));

            bool go = true;
            if(targetX == X && targetY == Y){
                go = false;
            }

            while(go){
                int ix = X + offer_X[id];
                int iy = Y + offer_Y[id];
                
                if(!check(ix, iy))
                    break;
                
                if(!visitied[iy][ix]){
                    cnt++;
                    visitied[iy][ix] = 1;

                    // 쓰러트린 범위 계산
                    int iix = ix + (offer_X[id] * (board[iy][ix]-1));
                    int iiy = iy + (offer_Y[id] * (board[iy][ix]-1));
                    if(id == 0 || id == 2){
                        if(targetX <= iix && targetY <= iiy)
                        {
                            targetX = iix, targetY = iiy;
                        }
                    }else{
                        if(targetX >= iix && targetY >= iiy)
                        {
                            targetX = iix, targetY = iiy;
                        }
                    }
                }

                X = ix, Y = iy;
                if(targetX == X && targetY == Y)
                    break;
            }
        }

        cin >> Y >> X;
        if(visitied[Y][X]){
            visitied[Y][X] = 0;
        }
    
        result += cnt;
    }


    pri();

    return 0;
}