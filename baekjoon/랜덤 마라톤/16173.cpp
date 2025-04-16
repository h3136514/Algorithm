#include <iostream>
#include <queue>

using namespace std;
int N, board[3][3], visitied[3][3];
queue<pair<int, int>> q;

bool check(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool bfs(){
    q.push({0, 0});
    visitied[0][0] = 1;

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        int value = board[currentY][currentX];
        q.pop();

        if(value == -1)
            return true;
        
        // 오른쪽 이동 확인
        if(check(currentX+value, currentY) && !visitied[currentY][currentX+value]){
            visitied[currentY][currentX+value] = 1;
            q.push({currentX+value, currentY});
        }

        // 아래 이동 확인
        if(check(currentX, currentY+value) && !visitied[currentY+value][currentX]){
            visitied[currentY+value][currentX] = 1;
            q.push({currentX, currentY+value});
        }
    }

    return false;
}

// 점프왕 쩰리 (Small)
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    if(bfs())
        cout << "HaruHaru\n";
    else
        cout << "Hing\n";

    return 0;
}