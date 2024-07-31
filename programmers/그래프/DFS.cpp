#include <cstdio>
#include <iostream>
#include<unordered_map>
#include <vector>
#include <queue>
#include <algorithm>    //fill 함수 사용

using namespace std;
unordered_map<char, int> mapping;  // 문자별 인덱스 매핑
vector<char> V[1001];
vector<char> result;
int cnt, num[1001];    //방문표시

// DFS
void dfs(char start) {
    int node = mapping[start];
    // 이미방문했으면
    if(num[node])
        return;

    num[node] = 1; // 방문완료
    result.push_back(start);
    for(int i=0; i < V[node].size(); i++){
        char x = V[node][i];
        dfs(x);
    }
}
// 정점의 수 : 𝑉, 간선의 수 : E라 하면, DFS의 시간 복잡도 : O(V + E)
vector<char> solution(vector<pair<char, char>> graph, char start)  {
    for(int i = 0; i < graph.size(); i++) {
        char u = graph[i].first;
        char v = graph[i].second;
        // char -> int 매핑
        if(mapping.find(u) == mapping.end())
            mapping[u] = cnt++;
        if(mapping.find(v) == mapping.end())
            mapping[v] = cnt++;
        // 단반향 간선 대입
        V[mapping[u]].push_back(v);
    }
    // 깊이 우선 탐색 시작
    dfs(start);

    return result;
}

void print(vector<char> vec)
{
    cout << vec[0];
  for(int i =1; i < vec.size(); i++){
        cout << " " << vec[i];
    }
  cout << endl;
}

// 초기화
void init() {
    mapping.clear();
    for (int i = 0; i <= cnt; i++) 
        V[i].clear();
    result.clear();
    fill(num, num + 1001, 0);
    cnt=0;
}

int main()
{
    print(solution({{'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'}}, 'A')); //출력값 : A B C D E
    init();
    print(solution({{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'E', 'F'}}, 'A')); //출력값 : A B D E F C

  return 0;
}

// 문자별 인덱스 매핑을 안하는(unordered_map을 안사용하는) 방식
/*
#include <unordered_set>

unordered_map<char, vector<char>> adjList;
vector<char> result;
unordered_set<char> visited;

void dfs(char node) {
  // 현재 node를 방문한 목록 및 방문한 경로 추가
  visited.insert(node);
  result.push_back(node);

  // 현재 node와 인접한 노드 중, 방문하지 않은 node들에 대해 깊이우선탐색을 계속 진행
  for (char neighbor : adjList[node]) {
    if (visited.find(neighbor) == visited.end()) {
      dfs(neighbor);
    }
  }
}

*/