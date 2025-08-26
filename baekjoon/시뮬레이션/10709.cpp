#include <iostream>
#include <queue>

using namespace std;
int H, W, num[101][101];
char board[101][101];
queue<pair<int, pair<int, int>>> q;

// 기상캐스터
int main(){
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> board[i][j];
            if(board[i][j] =='c'){
                q.push({0, {j, i}});
            }else
                num[i][j] = -1;
        }
    }

    while(!q.empty()){
        int cnt = q.front().first + 1;
        int x = q.front().second.first+1;
        int y = q.front().second.second;
        q.pop();
        
        if(x >= W || num[y][x] != -1 )
            continue;
        
        num[y][x] = cnt;
        q.push({cnt, {x, y}});
    }

     for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << num[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}