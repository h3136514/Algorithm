#include<vector>
#include<queue>

using namespace std;
queue<pair<int,int>> q;
int n, m, x, y;
int visit[101][101];    //방문 유무
int dist[101][101];     //해당 좌표까지 거리합
// 오프셋
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 좌표가 유효한지 확인
bool isRange(int isX, int isY) {
    return 0 <= isX && m > isX && 0 <= isY && n > isY;
}

int bfs(int startX, int startY, vector<vector<int> > maps) {
    visit[startY][startX] = 1;
    dist[startY][startX] = 1;
    q.push({startX, startY});
    
    while(!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();
        // 목적지에 도달했으면 해당 목적지 까지 이동횟수를 반환
        if(currentX == m-1 && currentY == n-1)
            return dist[currentY][currentX];

        // 현재위치 기준 상하좌우를 확인     
        for(int i = 0; i < 4; i++) {
            int ix = currentX + dx[i];
            int iy = currentY +dy[i];
            // 범위나 좌표이고 벽이 아닌 경우
            if(isRange(ix, iy) && !visit[iy][ix] && maps[iy][ix] != 0) {
                q.push({ix, iy});
                visit[iy][ix] = 1;
                dist[iy][ix] = dist[currentY][currentX] + 1;
            }
        }
    }
    
    return -1;
}

// 최대한 빨리 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값을 반환(시간 복잡도 : O(N*M))
int solution(vector<vector<int> > maps)
{   
    n = maps.size();
    m = maps[0].size();
    
    int answer = bfs(0, 0, maps);
    
    return answer;
}


#include <iostream>

using namespace std;

void init()
{
  for(int i = 0 ; i < n; i++)
    for(int j = 0 ; j < m; j++){
        visit[i][j] = 0;
        dist[i][j] = 0;
    }
}

int main()
{
  cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}}) << endl; //출력값 : 11
  init();
  cout << solution({{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}}) << endl; //출력값 : -1

  return 0;
}