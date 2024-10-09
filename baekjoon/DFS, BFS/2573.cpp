// BFS
#include <iostream>
#include <map>
#include <queue>

using namespace std;
int N, M, CNT, earth[301][301], visitied[301][301]; 
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
map<pair<int,int>, int> m;  // 빙산 관리
queue<pair<int, int>> q;

// 방문 초기화
void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visitied[i][j] = 0;
        }
    }
}

// 범위 확인
bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N;
}
/*
void printMap(){
    cout <<"-------------\n";
    for(auto i : m){
        cout << i.first.first << "," <<i.first.second<<" : " << i.second << "\n";
    }
    cout <<"-------------\n";
}

void printEarth(){
    cout <<"-------------\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
             cout << earth[i][j] <<" ";
        }
        cout <<"\n";
    }
    cout <<"-------------\n";
}
*/

// bfs(빙하 주변 얼음 및 바다 탐색)
int bfs(int x, int y){
    int cnt = 1;
    q.push({x, y});

    visitied[y][x] = 1;
    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        pair<int, int> p ={currentX, currentY};
        q.pop();
    
        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            if(check(ix, iy) && earth[iy][ix] == 0 && earth[currentY][currentX] != 0 && !visitied[iy][ix]){ // visitied[ix][iy] => 방근바뀐 빙하이므로 신경X
                earth[currentY][currentX]--;
                if(m.find(p) != m.end()){
                    if(earth[currentY][currentX] > 0)
                        m[p]--;
                    else
                        m.erase(p);
                }
            }
            if(check(ix, iy) && earth[iy][ix] != 0 && !visitied[iy][ix]){
                visitied[iy][ix] = 1;
                q.push({ix, iy});
                cnt++;
            }
        }
    }

    return cnt;
}

// 빙산
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> earth[i][j];
            if(earth[i][j] != 0){
                pair<int, int> p ={j, i};
                m[p] = earth[i][j];
            }
        }
    }

    while(true){
        if(m.size() == 0){
            cout << 0 <<"\n";
            break;
        }
        int snowSize = m.size();

        auto snow = m.begin();  // 맨 앞 빙하원소
        int snowCount = bfs(snow->first.first, snow->first.second); 
        if(snowSize != snowCount){  // 전체 빙하가 다 연결되어 있지 않았으므로
            cout << CNT <<"\n";
            break;
        }

        init();
        CNT++;  // 1년 후

    }

    return 0;
}