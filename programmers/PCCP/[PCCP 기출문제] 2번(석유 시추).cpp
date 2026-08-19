#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;
vector<vector<int>> lands;
int n, m, visitied[501][501], dp[501], answer = 0;
int offer_X[4] = {1,0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
set<int> s;

void init(){
    for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
            visitied[i][j] = 0;
        } 
    }
}

bool check(int x, int y){
    return x >= 0 && x < m && y >= 0 && y < n;
}

void bfs(int x, int y){
    int cnt = 1;
    visitied[y][x] = 1;
    q.push({x, y});
    s.insert(x);
    
    while(!q.empty()){
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int ix = currentX + offer_X[i];
            int iy = currentY + offer_Y[i];
            if(check(ix, iy) && !visitied[iy][ix] && lands[iy][ix]){
                cnt++;
                visitied[iy][ix] = 1;
                q.push({ix, iy});
                s.insert(ix);
            }
        }
    }
    
    for(auto idx : s){
        dp[idx] += cnt;
    }
    s.clear();
}

int solution(vector<vector<int>> land) {
    lands = land;
    n = land.size();
    m = land[0].size();
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visitied[j][i] && land[j][i])
                bfs(i, j);
        }
    }
    
    for(int i = 0; i < m; i++){
         answer = max(answer, dp[i]);
    }
    
    return answer;
}