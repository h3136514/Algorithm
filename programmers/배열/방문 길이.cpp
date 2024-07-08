#include <string>
using namespace std;

// 전체 좌표평면(특정 방향으로 이동한 적이 있는지 체크)
int frame[11][11][4];
// 현재 좌표
int x1, y1;
// 임시 좌표
int x2, y2, r;

//캐릭터가 처음 걸어본 길의 길이 구하기(시간복잡도 : O(N))
int solution(string dirs) {
    int answer = 0;
    // 시작점 설정
    x1 = 5, y1 = 5;
    
    for(int i = 0; i < dirs.length(); i++) {
        x2 = x1;
        y2 = y1;
        if(dirs[i] == 'U'){
            y2++;
            r = 0;
        }
        else if(dirs[i] == 'R'){
            x2++;
            r = 1;
        }
        else if(dirs[i] == 'D'){
            y2--;
            r = 2;
        }
        else if(dirs[i] == 'L'){
            x2--;
            r = 3;
        }

        // 좌표평면을 벗어나는지 확인
        if(x2 < 0 || y2 < 0 || x2 > 10 || y2 > 10)
            continue;
        
        if(!frame[y1][x1][r]) {
            frame[y1][x1][r] = 1;
            frame[y2][x2][(r+2)%4] = 1; // 양방향 방문 체크
            answer++;
        }
        
        x1 = x2;
        y1 = y2;
    }
    return answer;
}

#include<iostream>

int main() {
    cout << solution("ULURRDLLU") << endl;  //7
    cout << solution("LULLLLLLU") << endl; // 7 

    return 0;
}

// 오프셋 배열 활용
/*
bool visited[11][11][4]; 

// 상하좌우로 좌표를 이동할 때 필요한 좌표의 오프셋 배열 
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool isNotValid(int x, int y)
{
    return x < 0 || y < 0 || x > 10 || y > 10;
}

// 현재와 반대 방향의 오프셋 배열 인덱스 반환
int opposite_direction(int dir)
{
    return (dir+2) % 4;
}

int solution(string dirs) {
   int answer = 0;
    int x = 5, y = 5, r;
    
    for (auto c : dirs) {
        if(c == 'U'){
            r = 0;
        }
        else if(c == 'R'){
            r = 1;
        }
        else if(c == 'D'){
            r = 2;
        }
        else if(c == 'L'){
            r = 3;
        }
        int nx = x + dx[r];
        int ny = y + dy[r];

        // 좌표평면을 벗어나는지 확인
        if (isNotValid(nx,ny)) {
            continue;
        }

         // 다음 좌표가 아직 방문하지 않은 좌표인 경우
        if(visited[y][x][r] == false) {
          // 방문이 중복 체크되지 않도록 해당 경로의 양방향을 방문 체크
            visited[y][x][r] = true;
            visited[ny][nx][opposite_direction(r)] = true;
            answer++;
        }
      // 현재좌표를 이동한 좌표로 업데이트
        x = nx;
        y = ny;
    }
    return answer;
}
*/