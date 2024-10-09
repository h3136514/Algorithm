// BFS
#include <iostream>
#include <queue>

using namespace std;
int F, S, G, U, D, visitied[1000001];
queue<pair<int, int>> q;

// 범위 확인
bool check(int x){
    return x >= 1 &&  x <= F;
}

// bfs(위, 아래층 탐색)
int bfs(){
    q.push({0, S});
    visitied[S] = 1;

    while(!q.empty()){
        int currentS = q.front().second;
        int currentCnt = q.front().first;
        q.pop();
        if(currentS == G){
            return currentCnt;
        }

        // 위로 
        int UpS = currentS + U;
        if(check(UpS) && !visitied[UpS]){
            visitied[UpS] = 1;
            q.push({currentCnt+1, UpS});
        }

        // 아래로
        int DownS = currentS - D;
        if(check(DownS) && !visitied[DownS]){
            visitied[DownS] = 1;
            q.push({currentCnt+1, DownS});
        }
    }

    return -1;
}

// 스타트링크
int main() {
    cin >> F >> S >> G >> U >> D;

    int result = bfs();

    if(result == -1)
        cout <<"use the stairs\n";
    else
        cout << result << "\n";

    return 0;
}