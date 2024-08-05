#include <string>
#include <vector>
#include <queue>

using namespace std;
int n, m, x, y, distanceL, distanceE;
int visit[101][101] = {0}; //방문 유무
// 오프셋 배열
int dx[4] = {1, 0,-1, 0};
int dy[4] = {0, 1, 0, -1};

// 좌표가 유효한 범위인지 확인
bool isRange(int isX, int isY) {
    return 0 <= isX && isX < m && 0 <= isY && isY < n;   
}

// 초기화
void init() {
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ;j++){
            visit[i][j] = 0;
        }
    }
}

int bfs(char start, char target, vector<string> maps) {
    queue<pair<int, pair<int,int>>> q;  // 거리합, 해당좌표를 저장하는 큐
    init();
    
    // 시작점 찾기
    for(int i =0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(maps[i][j] == start){
                x = j;
                y = i;
                break;
            }
        }
    }
    q.push({0, {x, y}});
    visit[y][x] = 1;
    
    while(!q.empty()) {
        int cnt = q.front().first;
        int currentX = q.front().second.first;
        int currentY = q.front().second.second;
        q.pop();
        
        // 목적지에 도달했으면 해당 목적지 까지 이동횟수를 반환
        if(maps[currentY][currentX] == target)
            return cnt;

        // 현재위치 기준 상하좌우를 확인     
        for(int i = 0; i < 4; i++) {
            int iX = currentX + dx[i];
            int iY = currentY + dy[i];

            // 아직 방문하지 않은 후보좌표 탐색대상으로 추가 
            if(isRange(iX,iY) && !visit[iY][iX] && maps[iY][iX] != 'X') {
                q.push({cnt + 1, {iX, iY}});
                visit[iY][iX] = 1;
            }
        }
    }
    
    return -1;
}

// 통로들 중 한 칸에는 미로를 빠져나가는 문이 있는데, 이 문은 레버를 당겨서만 열 수 있습니다. 모든 통로, 출구, 레버, 시작점은 여러 번 지나갈 수 있을 때 미로를 탈출하는데 필요한 최소 시간을 반환(시간 복잡도 : O(N^2))
int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    
    // 시작지점부터 L까지 최단거리를 구함 
    distanceL = bfs('S', 'L', maps);
    // L부터 도착지점까지 최단거리를 구함
    distanceE = bfs('L', 'E', maps);
 
    if(distanceL == -1 || distanceE == -1)
        return -1;

    return distanceL + distanceE;
}


#include <iostream>

int main()
{
  cout << solution({"SOOOL", "XXXXO", "OOOOO", "OXXXX", "OOOOE"}) << endl; //출력값 : 16
  cout << solution({"LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO"}) << endl; //출력값 : -1
  
  return 0;
}