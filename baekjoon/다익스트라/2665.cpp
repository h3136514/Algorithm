#include <iostream>
#include <queue>

#define INF 987654321
using namespace std;
int N, visitied[51][51], answer = INF;
char num[51][51];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
priority_queue<pair<int, pair<int, int>>> q;

bool check(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

void dijsktra(){
    q.push({0, {0, 0}});
    visitied[0][0] = 0;

    while(!q.empty()){
        int currentBlack = -q.top().first;
        int currentX = q.top().second.first;
        int currentY = q.top().second.second;
        q.pop();

        if(visitied[currentY][currentX] < currentBlack){
            continue;
        }

        if(currentX == N-1 && currentY == N-1){
            answer = currentBlack;
            break;
        }

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && num[iy][ix] == '1' && visitied[iy][ix] > currentBlack){
                visitied[iy][ix] = currentBlack;
                q.push({-currentBlack, {ix, iy}});
            }else if(check(ix, iy) && num[iy][ix] == '0' && visitied[iy][ix] > currentBlack+1){
                visitied[iy][ix] = currentBlack + 1;
                q.push({-(currentBlack + 1), {ix, iy}});
            }
        }
    }
}

// 미로만들기
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num[i][j];
            visitied[i][j] = INF;
        }
    }

    dijsktra();

    cout << answer << "\n";

    return 0;
}