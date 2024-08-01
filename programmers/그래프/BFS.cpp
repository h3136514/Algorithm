#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>    //fill 함수 사용

using namespace std;
queue<int> q;
vector<int> result, V[1001];
int num[1001]; // 방문표시

// BFS
void bfs(int start) {
    // 시작 노드 방문
    q.push(start);
    num[start] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        result.push_back(x);

        // 현재 노드와 인접한 노드 중 아직 방문하지 않는 노드 방문
        for(int i = 0; i < V[x].size(); i++){
            int y = V[x][i];
            // 방문을 안했으면
            if(!num[y]) {
                q.push(y);
                num[y] = 1;
            }
        }
    }   
}

// 정점의 수 : 𝑉, 간선의 수 : E라 하면, BFS의 시간 복잡도 : O(V + E)
vector<int> solution(vector<pair<int, int>> graph, int start) {
    for(int i = 0; i < graph.size(); i++) {
        int u = graph[i].first;
        int v = graph[i].second;

        V[u].push_back(v);
    }
    // 너비 우선 탐색 시작
    bfs(start);

    return result;
}

#include <iostream>

void print(vector<int> vec)
{
    cout << vec[0];
    for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
    cout << endl;
}

void init() {
    result.clear();
    for(int i=0; i < 1001; i++)
        V[i].clear();
    fill(num, num + 1001, 0);
}

int main()
{
  
  print(solution({{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 9}, {7, 9}}, 1)); //출력값 : 1 2 3 4 5 6 7 8 9
  init();
  print(solution({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}}, 1)); //출력값 : 1 2 3 4 5 0
  return 0;
}