#include <string>
#include <vector>
#include <queue>

#define MAX 26
#define MAX_COST 999999
#define STRAIGHT_COST 100
#define CORNER_COST 600

using namespace std;
int roadSize, cost, dist[MAX][MAX][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<vector<int>> q;

// 좌표가 유효한 범위인지 확인
bool isRange(int isX, int isY) {
    return 0 <= isX && roadSize > isX && 0 <= isY && roadSize > isY;
}

void bfs(int startX, int startY, vector<vector<int>> maps) {
    // 시작점 설정
    dist[startX][startY][0] = 0;
    dist[startX][startY][1] = 0;
    q.push({startX, startY, 0});
    q.push({startX, startY, 1});
    
    while(!q.empty()) {
        vector<int> v = q.front();
        int currentX = v[0];
        int currentY = v[1];
        int dir = v[2]; // 방향
        q.pop();
        
        // 현재 지점을 기준으로 이동가능한 지점 확인  
        for(int i = 0; i < 4; i++) {
            int ix = currentX + dx[i];
            int iy = currentY + dy[i];
            
            if(isRange(ix,iy) && maps[iy][ix] != 1) {
                if(dir == i)
                    cost = dist[currentY][currentX][dir] + STRAIGHT_COST;
                else
                    cost = dist[currentY][currentX][dir] + CORNER_COST;
                
                if (dist[iy][ix][i] > cost) {
                    q.push({ix, iy, i});
                    dist[iy][ix][i] = cost;
                }
            }
        }
    }
    
}

// 초기화
void init() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            for(int k = 0; k < 4; k++)
                dist[i][j][k] = MAX_COST;
        }
    }
}

int solution(vector<vector<int>> board) {
    init();
    roadSize = board.size();
    bfs(0, 0, board);
    
    // 도착 지점까지 가는 모든 경로 중 최소 선택
    int answer = MAX_COST;
    for(int i = 0; i < 4; i++) {
        answer = answer > dist[roadSize-1][roadSize-1][i] ? dist[roadSize-1][roadSize-1][i] : answer;
    }
   
    return answer;
}


#include <iostream>

int main()
{
  
  cout << solution({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}) << endl; //출력값 : 900
  cout << solution({{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0},{0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}}
) << endl; //출력값 : 3800
  cout << solution({{0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 0}}) << endl; //출력값 : 2100
  cout << solution({{0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {1, 0, 0, 1, 0, 1}, {0, 1, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0}}) << endl; //출력값 : 3200

  return 0;
}