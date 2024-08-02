#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

#define INF 99999   // 가중치가 최대 10000이므로
#define MAX 10000   // 최대 노드 갯수 
using namespace std;
vector<pair<int, int>> V[MAX];
priority_queue<pair<int, int>> q;
int dp[MAX];    //노드별 최소비용을 저장할 공간

// 다익스트라 알고리즘
void dijkstra(int start) {
    dp[start] = 0;
    q.push({0, start});

    while(!q.empty()) {
        int cost = -q.top().first; //제일 작은 비용
        int here = q.top().second; //연결된 노드
        q.pop();

        // 이미 더 짧은 경로를 알고 있다면 무시
        if(dp[here] < cost)
            continue;
        
        // 인접한 정점들을 검사하여 경로 갱신
        for(int i = 0; i < V[here].size(); i++) {
            int next = V[here][i].first;
            int nextCost = V[here][i].second + cost;
            
            //작은비용 갱신
            if(dp[next] > nextCost) {
                dp[next] = nextCost;
                q.push({-nextCost, next});
            }
        }
    }

}
// 정점의 수 : 𝑉, 간선의 수 : E라 하면, 다익스트라 알고리즘의 시간 복잡도 : O(ElogV)
vector<int> solution(int start, int numNodes, const vector<tuple<int, int, int>> edges) {
    for(int i = 0; i < edges.size(); i++) {
        int u = get<0>(edges[i]);
        int v = get<1>(edges[i]);
        int c = get<2>(edges[i]);

        V[u].push_back({v, c});
    }

    dijkstra(start);
    
    vector<int> result;
    for(int i = 0; i < numNodes; i++)
        result.push_back(dp[i]);

    return result; 
}


// 초기화
void init() {
    fill(dp, dp + MAX, INF);    //비용 초기화(제일 큰값)
    for(int i = 0; i < MAX; i++)
        V[i].clear();
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

int main() {
    init();
    print(solution(0, 3, {{0, 1, 9},{0, 2, 3},{1, 0, 5},{2, 1, 1}})); //출력값 : 0 4 3
    init();
    print(solution(0, 4, {{0, 1, 1}, {1, 2, 5}, {2, 3, 1}})); //출력값 : 0 1 6 7
    
    return 0;
}

// 인접행렬로 푸는 방법(정점의 수 : 𝑉, 시간 복잡도 : O(V^2))
/*
const int INF = 99999;
const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

vector<int> solution(int start, int numNodes, const vector<tuple<int, int, int>> edges) {
  // 그래프 및 방문 여부 초기화
  for (int i = 0; i < MAX_NODES; ++i) {
    fill_n(graph[i], MAX_NODES, INF);
    visited[i] = false;
  }
  
  // 입력받은 간선 정보를 그래프로 표현
  for (const auto& [from, to, weight] : edges) {
    graph[from][to] = weight;
  }

  // 시작 노드를 제외한 모든 노드의 최소 비용을 INF로 초기화
  vector<int> distances(numNodes, INF);
  distances[start] = 0;

  for (int i = 0; i < numNodes - 1; ++i) {
    int minDistance = INF;
    int closestNode = -1;

    // 최소 거리 노드 찾기
    for (int j = 0; j < numNodes; ++j) {
      if (!visited[j] && distances[j] < minDistance) {
        minDistance = distances[j];
        closestNode = j;
      }
    }

    // 찾은 노드를 방문 처리
    visited[closestNode] = true;

    // 인접 노드에 대한 거리 업데이트
    for (int j = 0; j < numNodes; ++j) {
      int newDistance = distances[closestNode] + graph[closestNode][j];
      if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) {
        distances[j] = newDistance;
      }
    }
  }

  return distances;
}
*/