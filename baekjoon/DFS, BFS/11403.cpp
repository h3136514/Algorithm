// BFS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, num, visitied[101];
vector<int> v[101], result[101];
queue<int> q;

// 방문한 장소 표시 & 방문 초기화
void checkV(int start){
    for(int i = 1; i <= N; i++){
        result[start].push_back(visitied[i]);
        visitied[i] = 0;
    }
}

// bfs
void bfs(int start){
    q.push(start);

    while(!q.empty()){
        int currentV = q.front();
        q.pop();

        for(int i = 0; i < v[currentV].size(); i++){
            int iv = v[currentV][i];
            if(!visitied[iv]){
                visitied[iv] = 1;
                q.push(iv);
            }
        }
    }

    checkV(start);
}

// 경로 찾기
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> num;
            if(num)
                v[i].push_back(j);
        }
    }

    for(int i = 1; i <= N; i++){
        bfs(i);
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < N; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}