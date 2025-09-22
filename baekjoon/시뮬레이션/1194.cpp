#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define INF 987654321
using namespace std;
int N, M, startX, startY, CNT = INF;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
char board[51][51];
map<vector<int>, int> m;
queue<pair<int, vector<int>>> q;

// 범위 체크
bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N; 
}

void pri(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

// 열쇠 확인
bool checkKey(char c, vector<int> &v){
    if(c == 'A')
        return v[2] > 0;
    if(c == 'B')
        return v[3] > 0;
    if(c == 'C')
        return v[4] > 0;
    if(c == 'D')
        return v[5] > 0;
    if(c == 'E')
        return v[6] > 0;
    if(c == 'F')
        return v[7] > 0;

    return false;
}

void bfs(){
    vector<int> v;
    v.resize(8);
    v[0] = startX;
    v[1] = startY;

    m[v] = 1;
    q.push({0, v});

    while(!q.empty()){
        vector<int> currentV = q.front().second;
        int currentCnt = q.front().first;
        int currentX = currentV[0], currentY = currentV[1]; 
        q.pop();

        if(board[currentY][currentX] == '1'){
            CNT = currentCnt;
            break;
        }

        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            int iCnt = currentCnt + 1;
            vector<int> iV(currentV);
            
            iV[0] = ix, iV[1] = iy;

            if(!check(ix, iy))
                continue;
            
            int num = board[iy][ix];

            if(num >= 97 && num <= 102){
                int idx = num- 95;
                iV[idx] = 1;
            }else if((num >= 65 && num <= 70) &&(!checkKey(board[iy][ix], iV))){
                continue;
            }else if(board[iy][ix] == '#')
                continue;

            if(m.find(iV) == m.end()){
                m[iV] = 1;
                q.push({iCnt, iV});
            }

        }

    }
}

// 달이 차오른다, 가자.
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
            
            if(board[i][j] == '0'){
                startX = j;
                startY = i;
            }
        }
    }
    
    bfs();

    CNT = (CNT == INF) ? -1 : CNT;

    cout << CNT << "\n";

    return 0;
}
