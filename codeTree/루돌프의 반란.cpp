#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, M, P, C, D, RX, RY, SX, SY, board[51][51], score[31], live[31], sleep[31], num, CNT;
int offer_X[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int offer_Y[8] = {-1, 0, 1, 0, 1, -1, -1, 1};
priority_queue<pair<pair<int, int>, pair<int, int>>> dist;
vector<int>santa[31];

void init(){
    // 거리 저장 초기화
    while(!dist.empty())
        dist.pop();;
}
/*
void printBoard(){
     cout << "----------------------\n";
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
     cout << "----------------------\n";
}

void printSanta(){
     cout << "----------------------\n";
    for(int i =1 ; i <= P; i++){
        if(live[i])    // 탈락 안함 산타
        {   
            cout << santa[i][1] << " " << santa[i][0] <<"\n";
        }
    }
     cout << "----------------------\n";
}
*/

bool check(int x, int y){
    return x >= 1 && x <=N && y >= 1 && y <= N;
}

void saveScore(){
    for(int i = 1; i <= P; i++){
        if(live[i]){
            score[i]++;
        }
    }
}

// 루돌프 이동
void Rmove(int c){
    // 이동할 산타 정하기
    for(int i =1 ; i <= P; i++){
        if(live[i])    // 탈락 안함 산타
        {   
            int x = santa[i][0];
            int y = santa[i][1];
            int d = (RX-x)*(RX-x) + (RY-y)*(RY-y);

            dist.push({{-d,y}, {x, i}});
        }
    }
    int targetX = dist.top().second.first;
    int targetY = dist.top().first.second;
    int id = dist.top().second.second;

    // 거리 저장 초기화
    while(!dist.empty())
        dist.pop();;

    // 가장 가까운 방향 정하기
    for(int i =0 ; i < 8; i++){
        int x = RX + offer_X[i];
        int y = RY + offer_Y[i];
        if(!check(x, y))
            continue;

        int d = (targetX-x)*(targetX-x) + (targetY-y)*(targetY-y);

        dist.push({{-d, y},{x, i}});
    }
    // 루돌프 이동
    RX = dist.top().second.first;
    RY = dist.top().first.second;
    int r = dist.top().second.second;

    //산타와 부딪히면
    if(RX == targetX && RY == targetY){
        score[id] += C;
        board[targetY][targetX] = 0;
        sleep[id] = c + 1;
        int x = targetX + offer_X[r]*C;
        int y = targetY + offer_Y[r]*C;
        if(!check(x, y)){
            CNT--;
            live[id] = 0;
            return;
        }

        santa[id][0] = x;
        santa[id][1] = y;
        if(board[y][x] > 0){
            int iid;
            while(true) { //연쇄 반응
                iid = board[y][x];
                board[y][x] = id;
                x = x + offer_X[r];
                y = y + offer_Y[r];
                if(!check(x, y)){
                        CNT--;
                        live[iid] = 0;
                        return;
                }
                id = iid;
                santa[id][0] = x;
                santa[id][1] = y;

                if(board[y][x] == 0){
                    board[y][x] = id;
                    return;
                }
            }
        }else
            board[y][x] = id;
    }
}

// 산타 이동
void Smove(int c, int id) {
    int x = santa[id][0];
    int y = santa[id][1];

    int distance = (RX-x)*(RX-x) + (RY-y)*(RY-y); 
    // 가장 가까운 방향 정하기
    for(int i =0 ; i < 4; i++){
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];
        if(!check(ix, iy) || board[iy][ix] > 0)
            continue;

        int d = (RX-ix)*(RX-ix) + (RY-iy)*(RY-iy);

        dist.push({{-d, -i},{ix, iy}});
    }
    // 갈 수 있는 경우X
    if(dist.size() == 0)
        return;
    // 가까워 질 수 있는 경우X
    int targetD = -dist.top().first.first;
    if(targetD >= distance)
        return;
    
    int targetX = dist.top().second.first;
    int targetY = dist.top().second.second;
    int r = -dist.top().first.second;
    
    board[y][x] = 0;
    //루돌프와 부딪히면
    if(RX == targetX && RY == targetY){
        score[id] += D;
        sleep[id] = c + 1;

        int ix = targetX + offer_X[(r+2)%4]*D;
        int iy = targetY + offer_Y[(r+2)%4]*D;
        if(!check(ix, iy)){
            CNT--;
            live[id] = 0;
            return;
        }

        santa[id][0] = ix;
        santa[id][1] = iy;
        if(board[iy][ix] > 0){
            int iid;
            while(true) { //연쇄 반응
                iid = board[iy][ix];
                board[iy][ix] = id;
                ix = ix + offer_X[(r+2)%4];
                iy = iy + offer_Y[(r+2)%4];
                if(!check(ix, iy)){
                        CNT--;
                        live[iid] = 0;
                        return;
                }
                id = iid;
                santa[id][0] = ix;
                santa[id][1] = iy;

                if(board[iy][ix] == 0){
                    board[iy][ix] = id;
                    return;
                }
            }
        }else
            board[iy][ix] = id;

    }else{
        board[targetY][targetX] = id;
        santa[id][0] = targetX;
        santa[id][1] = targetY;
    }

    
}

int main(){
    cin >> N >> M >> P >> C >> D;
    CNT = P;
    cin >> RY >> RX;

    for(int i =1 ; i <= P; i++){
        cin >> num >> SY >> SX;
        santa[num].push_back(SX);
        santa[num].push_back(SY);
        board[SY][SX] = num;
        
        live[num] = 1;
    }

    //게임 진행
    for(int i =1 ; i <= M; i++){
        if(CNT <= 0) // 남은 산타X
            break;

        Rmove(i); //루돌프 이동
        init();
        for(int j =1 ; j <= P; j++){
            if(live[j] && sleep[j] < i){    // 탈락 안함 & 기절 안함 산타
                Smove(i, j);
                // 거리 저장 초기화
                while(!dist.empty())
                    dist.pop();;
            }
        }

        saveScore();
    }

    for(int i =1 ; i <= P; i++)
        cout << score[i] << " ";

    return 0;
}