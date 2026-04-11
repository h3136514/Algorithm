// https://www.acmicpc.net/problem/3184
#include <iostream>
#include <queue>

using namespace std;
int R, C, visitied[251][251], wolfSum, sheepSum;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
char S[251][251];
queue<pair<int, int>> q;

bool check(int x, int y){
    return x >= 0 && x < C && y >= 0 && y < R;
}

void bfs(int startX, int startY){
    int wolfCnt = 0, sheepCnt = 0;
    visitied[startY][startX] = 1;
    q.push({startX, startY});
    if(S[startY][startX] == 'v')
        wolfCnt++;
    else if(S[startY][startX] == 'o')
        sheepCnt++;
    
    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && S[iy][ix] != '#'){
                if(S[iy][ix] == 'v')
                    wolfCnt++;
                else if(S[iy][ix] == 'o')
                    sheepCnt++;

                visitied[iy][ix] = 1;
                q.push({ix, iy});
            }
        }
    }
    if(wolfCnt < sheepCnt)
        wolfSum -= wolfCnt;
    else
        sheepSum -= sheepCnt;
}

// 양
int main(){
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> S[i][j];
            if(S[i][j] == 'v')
                wolfSum++;
            else if(S[i][j] == 'o')
                sheepSum++;
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(!visitied[i][j] && S[i][j] != '#'){
                bfs(j, i);
            }
        }
    }

    cout << sheepSum << " " << wolfSum << "\n";

    return 0;
}
