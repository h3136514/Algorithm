#include <iostream>

using namespace std;
int N, target, targetX, targetY, board[1000][1000], x, y, d = -1, CNT = 1, num = 1;
int offer_X[4] = {0, 1, 0, -1};
int offer_Y[4] = {-1, 0, 1, 0};
bool check = false;

void pri(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << targetY << " " << targetX << "\n";
}

// 달팽이
int main(){
    cin >> N;
    cin >> target;
    x = N/2;
    y = N/2;

    board[y][x] = num;
    if(target == 1){
        targetX = x + 1;
        targetY = y + 1;
    }

    while(true){
        for(int i = 0; i < 2; i++){
            d = (d == 3) ? 0 : d + 1;
            for(int j = 0; j < CNT; j++){
                num++;

                x += offer_X[d];
                y += offer_Y[d];
                board[y][x] = num;
                
                if(num == target){
                    targetX = x + 1;
                    targetY = y + 1;
                }

                if(num == N*N){
                    pri();
                    
                    return 0;
                }
            }
        }

        CNT++;
    }

    return 0;
}