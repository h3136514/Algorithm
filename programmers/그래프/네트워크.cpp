#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int cnt, visited[201];

// 깊이 우선 탐색(DFS)
void dfs(int start, vector<vector<int>> &computers) {
    visited[start] = 1;
    
    for(int i = 0; i < computers[start].size(); i++) {
        if(computers[start][i] && !visited[i])
            dfs(i, computers);
    }
}

// 연결된 네트워크의 개수를 반환(인접행렬로 구현했으므로 시간 복잡도 : O(N^2))
int solution(int n, vector<vector<int>> computers) {
    // 네트워크의 수를 확인
    for(int i = 0; i < n; i++)
        if(!visited[i]) {
            dfs(i, computers);
            cnt++;
        }
    
    return cnt;
}


#include <iostream>

void init()
{
    fill(visited, visited + 201, 0);
    cnt = 0;
}

int main()
{
  
  cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl; //출력값 : 2
  init();
  cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl; //출력값 : 1

  return 0;
}

// 유니온 파인드(DFS 사용X)
/*
#include <unordered_map>

using namespace std;
unordered_map<int, bool> networkFound;
int parent[201];

int find(int a) {
    if(parent[a] == a)
        return a;
    return parent[a] = find(parent[a]);
}

void union_s(int a, int b) {
    int root1 = find(a);
    int root2 = find(b);

    if(root1 == root2)
        return;
    parent[root2] = root1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer;
    // 각 노드의 부모를 자기 자신으로 초기화
    for(int i = 0; i < n; i++)
        parent[i] =i;
    
    // 연결된 컴퓨터를 그룹화
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(computers[i][j])
                union_s(i, j);
    
    for(int i = 0; i < n; i++) {
        int root = find(i); // 각 노드의 루트 노드 찾기
        // 새로운 네트워크 발견 시 카운트 증가
        if(!networkFound[root]) {
            answer++;
            networkFound[root] = true;
        }

    }
    
    return answer;
}
*/

