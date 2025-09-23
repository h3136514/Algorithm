#include <iostream>
#include <queue>
#include <map>

using namespace std;
int N, totall, num, fri, board[21][21], sum;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
priority_queue<pair<pair<int, int>, pair<int, int>>> q;
map<pair<int, int>, int> like;

bool check(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

// 빈칸 계산
int checkWhite(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];

        if(check(ix, iy) && board[iy][ix] == 0){
            cnt++;
        }
    }

    return cnt;
}

// 친구수 계산
int checkFriendly(int x, int y, int target){
    int cnt = 0;
    for(int i = 0; i < 4; i++){
        int ix = x + offer_X[i];
        int iy = y + offer_Y[i];

        if(check(ix, iy) && board[iy][ix] != 0){
            if(like.find({target, board[iy][ix]}) != like.end())
                cnt++;
        }
    }

    return cnt;
}

// 자리 배치
void batch(int target){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!board[i][j]){
                int whiteCnt = checkWhite(j, i);
                int freindCnt = checkFriendly(j, i, target);
                q.push({{freindCnt, whiteCnt},{-i, -j}});
                
            }
        }
    }

    int x = -q.top().second.second;
    int y = -q.top().second.first;
    
    board[y][x] = target;

    while(!q.empty())
        q.pop();
}

// 점수 계산
void cal(){
     for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int freindCnt = checkFriendly(j, i, board[i][j]);
            if(freindCnt == 1)
                sum += 1;
            else if(freindCnt == 2)
                sum += 10;
            else if(freindCnt == 3)
                sum += 100;
            else if(freindCnt == 4)
                sum += 1000;
        }
    }
}
void pri(){
     for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// 상어 초등학교
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    cin >> N;
    totall = N*N;
    
    for(int i = 0; i < totall; i++){
        cin >> num;
        for(int j = 0; j < 4; j++){
            cin >> fri;
            like[{num, fri}] = 1;
        }

        batch(num);
    }

    cal();

    cout << sum << "\n";

    return 0;
}
