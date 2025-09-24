#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <stack>

using namespace std;
int N, M, sum, board[21][21], tmp[21][21], visitied[6][21][21], targetX = -1, targetY= -1;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
map<pair<int,int>, vector<pair<int, int>>> blocks;
map<pair<int,int>, int> rainbows;
queue<pair<int, int>> q;
priority_queue<pair<pair<int, int>, pair<int, int>>> findQ;
stack<int> s;

bool check(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

void copyBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tmp[i][j] = board[i][j];
        }
    }
}

void pastBoard(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

void init(){
    targetX = -1, targetY = -1;
    for(int k = 1; k < 6; k++){
         for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                visitied[k][i][j] = 0;
            }
        }
    }

    while(!findQ.empty())
        findQ.pop();

    blocks.clear();
    rainbows.clear();
}

bool bfs(int startX, int startY){
    vector<pair<int, int>> v;
    int cnt = 1, rainbowCnt = 0, targetNum = board[startY][startX];
    q.push({startX, startY});
    v.push_back({startX, startY});

    visitied[targetNum][startY][startX] = 1;

    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            
            if(check(ix, iy) && !visitied[targetNum][iy][ix] && (board[iy][ix] == targetNum || board[iy][ix] == 0)){
                visitied[targetNum][iy][ix] = 1;
                cnt++;
                v.push_back({ix, iy});
                q.push({ix, iy});

                if(board[iy][ix] == 0)
                    rainbowCnt++;
            }
        }

    }

    rainbows[{startX, startY}] = rainbowCnt;
    blocks[{startX, startY}] = v;
    v.clear();

    if(cnt < 2)
        return false;

    return true;
}


bool findBlock(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] != -1 && board[i][j] != 6 && board[i][j] != 0){
                if(visitied[board[i][j]][i][j])
                    continue;

                if(bfs(j, i)){
                    vector<pair<int, int>> v = blocks[{j, i}];
                    findQ.push({{v.size(), rainbows[{j, i}]},{i, j}});
                }
            }
        }
    }

    if(findQ.empty())
        return false;

    targetX = findQ.top().second.second, targetY= findQ.top().second.first;

    return true;

}

// 중력 이동
void grabity(){
    for(int i = 0; i < N; i++){ // 한 열마다 보기(x)
        for(int j = 0; j < N; j++){
            if(board[j][i] == 6)
                continue;
            
            if(board[j][i] == -1){
                int cnt = 1;
                while(!s.empty()){
                    board[j-cnt++][i] = s.top();
                    s.pop();
                }
            }else{
                s.push(board[j][i]);
                board[j][i] = 6;
            }
        }

        int cnt = 1;
        while(!s.empty()){
            board[N-cnt++][i] = s.top();
            s.pop();
        }
    }
}

// 반시계 90도 회전
void rotate(){
    copyBoard();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            board[N-1-j][i] = tmp[i][j];
        }
    }
}

void pri(){
    cout << "-----------------------\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
     cout << "-----------------------\n";
}

// 상어 중학교
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }

    while(true){
        if(!findBlock())
            break;
        
        vector<pair<int, int>> v =  blocks[{targetX, targetY}];
        int blockCnt =v.size();
        for(int i = 0; i < blockCnt; i++){
            int x = v[i].first;
            int y = v[i].second;
            board[y][x] = 6;
        }
        sum += (blockCnt*blockCnt);
       
        grabity();
        
        rotate();
        
        grabity();

        init();
    }

    cout << sum << "\n";

    return 0;
}