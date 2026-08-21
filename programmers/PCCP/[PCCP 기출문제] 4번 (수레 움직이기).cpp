#include <string>
#include <vector>
#define INF 987654321
using namespace std;
int redVisitied[5][5], blueVisitied[5][5], answer = INF;
int N, M, rEx, rEy, bEx, bEy;
int offer_X[4] = {1, 0, -1, 0};
int offer_Y[4] = {0, 1, 0, -1};

bool check(int x, int y){
    return x >= 0 && x < M && y >= 0 && y < N; 
}

void backtracking(int rSx, int rSy, int bSx, int bSy, int cnt, bool checkR, bool checkB, vector<vector<int>> mazes){
    if(rSx == rEx && rSy == rEy && bSx == bEx && bSy == bEy){
        answer = min(answer, cnt);
        return;
    }
    
    if(checkR && checkB){
        checkR = false;
        checkB = false;
    }
    
    bool rAtDest = (rSx == rEx && rSy == rEy);
    bool bAtDest = (bSx == bEx && bSy == bEy);
    
    // 빨간 움직임
    if(!checkR){
        if(rAtDest){
            // 도착한 수레는 움직이진 않지만 이번 턴은 소비한 것으로 처리
            int icnt = checkB ? cnt : cnt+1;
            backtracking(rSx, rSy, bSx, bSy, icnt, true, checkB, mazes);
        } else {
            for(int i = 0; i < 4; i++){
                int ix = rSx + offer_X[i];
                int iy = rSy + offer_Y[i];
                if(check(ix, iy) && mazes[iy][ix] != 5 && !redVisitied[iy][ix] && !(ix == bSx && iy == bSy)){
                    redVisitied[iy][ix] = 1;
                    int icnt = checkB ? cnt : cnt+1;
                    backtracking(ix, iy, bSx, bSy, icnt, true, checkB, mazes);
                    redVisitied[iy][ix] = 0;
                }
            }
        }
    }
       
    // 파란 움직임
    if(!checkB){
        if(bAtDest){
            int icnt = checkR ? cnt : cnt+1;
            backtracking(rSx, rSy, bSx, bSy, icnt, checkR, true, mazes);
        } else {
            for(int i = 0; i < 4; i++){
                int ix = bSx + offer_X[i];
                int iy = bSy + offer_Y[i];
                if(check(ix, iy) && mazes[iy][ix] != 5 && !blueVisitied[iy][ix] && !(ix == rSx && iy == rSy)){
                    blueVisitied[iy][ix] = 1;
                    int icnt = checkR ? cnt : cnt+1;
                    backtracking(rSx, rSy, ix, iy, icnt, checkR, true, mazes);
                    blueVisitied[iy][ix] = 0;
                }
            }
        }
    }
}

int solution(vector<vector<int>> maze) {
    int rSx, rSy, bSx, bSy;
    N = maze.size();
    M = maze[0].size();
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(maze[i][j] == 1){
                rSx = j, rSy = i;
                redVisitied[i][j] = 1;
            }else if(maze[i][j] == 2){
                bSx = j, bSy = i;
                blueVisitied[i][j] = 1;
            }else if(maze[i][j] == 3){
                rEx = j, rEy = i;
            }else if(maze[i][j] == 4){
                bEx = j, bEy = i;
            }
        } 
    }
    
    backtracking(rSx, rSy, bSx, bSy, 0, false, false, maze);
    if(answer == INF)
        answer = 0;
    
    return answer;
}