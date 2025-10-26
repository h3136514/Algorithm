#include <iostream>

#define MAX 987654321
using namespace std;
int N, G[11][11], visitied[11][11], CNT = MAX;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};

bool check(int x, int y){
    return !visitied[y][x] && !visitied[y-1][x] && !visitied[y+1][x]&& !visitied[y][x-1] && !visitied[y][x+1];
}

void backtrack(int sum, int cnt){
    if(cnt == 3){
        CNT = min(CNT, sum);
        return;
    }

    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < N-1; j++){
            if(check(j, i)){
                int isum = G[i][j];
                visitied[i][j] = 1;

                for(int k = 0; k < 4; k++){
                    int ix = j + offer_X[k];
                    int iy = i + offer_Y[k];

                    visitied[iy][ix] = 1;
                    isum += G[iy][ix];
                }

                backtrack(sum + isum, cnt + 1);

                visitied[i][j] = 0;
                for(int k = 0; k < 4; k++){
                    int ix = j + offer_X[k];
                    int iy = i + offer_Y[k];

                    visitied[iy][ix] = 0;
                }
            }
        }
    }

}

// 꽃길
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> G[i][j];
        }
    }

    backtrack(0, 0);

    cout << CNT << "\n";
}