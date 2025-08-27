#include <iostream>
#include <queue>
#include <string>

using namespace std;
int N, CNT, endX, endY, visitied[2001][2001];
int offer_X[7] = {0, 1, -1, 1, 1, -1, -1};
int offer_Y[7] = {-1, 0, 0, 1, -1, 1, -1};
string s[2001];
queue<pair<int, int>> q;

bool check(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

void bfs(){
    q.push({endX, endY});
    visitied[endY][endX] = 1;

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 7; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && s[iy][ix] == '.'){
                visitied[iy][ix] = 1;
                CNT++;
                q.push({ix, iy});
            }
        }
    }
}

// W키가 빠진 성원이
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
           if(s[i][j] == 'F'){
                endX = j, endY = i;
            }
        }
    }

    bfs();

    cout << CNT << "\n";

    return 0;
}