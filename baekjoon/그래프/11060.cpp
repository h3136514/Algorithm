// https://www.acmicpc.net/problem/11060
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, visitied[1001], CNT = -1;
vector<int> v;
queue<pair<int, int>> q;

void bfs(){
    if(N == 1){
        CNT = 0;
        return;
    }

    visitied[0] = 1;
    q.push({0, 0});

    while(!q.empty()){
        int currentV = q.front().first;
        int currentCnt = q.front().second;
        q.pop();

        for(int i = 1; i <= v[currentV]; i++){
            int iv = currentV + i;
            int icnt = currentCnt +1;
            if(N-1 <= iv){
                CNT = icnt;
                return;
            }

            if(!visitied[iv]){
                visitied[iv] = 1;
                q.push({iv, icnt});
            }
        }
    }
}

// 점프 점프
int main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }

    bfs();

    cout << CNT << "\n";

    return 0;
}