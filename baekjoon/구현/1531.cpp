#include <iostream>

using namespace std;
int N, M, picture[101][101], sx, sy, ex, ey, cnt;

// 투명
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> sx >> sy >> ex >> ey;
        for(int j = sx; j <= ex; j++){
            for(int k = sy; k <= ey; k++){
                picture[k][j]++;
            }
        }
    }

    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(picture[i][j] > M)
                cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}