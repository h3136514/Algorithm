// https://www.acmicpc.net/problem/1303
#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;
int N, M, sumB, sumW, visitied[101][101];
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
string s[101];
queue<pair<int, int>> q;

bool check(int x, int y){
    return x >= 0 && y >= 0 && y < N && x < M;
}

int bfs(char c, int startX, int startY){
    visitied[startY][startX] = 1;
    int cnt = 1;
    char target = s[startY][startX];
    q.push({startX, startY});

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];

            if(check(ix, iy) && !visitied[iy][ix] && s[iy][ix] == target){
                visitied[iy][ix] = 1;
                cnt++;
                q.push({ix, iy});
            }
        }
    }

    return cnt;
}

// 전쟁 - 전투
int main(){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visitied[i][j]){
                int cnt = bfs(s[i][j], j, i);

                if(s[i][j] =='W'){
                    sumW += pow(cnt, 2);
                }else{
                    sumB += pow(cnt, 2);
                }
            }
        }
    }

    cout << sumW << " " << sumB << "\n";

    return 0;
}