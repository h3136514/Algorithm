#include <vector>
#include <tuple>
#include <algorithm>

#define INF 99999 // 가중치가 최대 100이므로
#define MAX 100 // 최대 노드 갯수
using namespace std;
vector<pair<int, int>> V[MAX];
int dist[MAX]; //노드별 최소비용을 저장할 공간

// 정점의 수 : V, 간선의 수 : E라 하면, 벨만포드 알고리즘의 시간 복잡도 : O(V*E)
vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source) {
    for(int i = 0; i < edges.size(); i++) {
        int u, v, c;
        tie(u, v, c) = edges[i];

        V[u].push_back({v, c});
    }
    // 시작점
    dist[source] = 0;

    // 정점의 개수 -1 만큼 최소비용을 갱신
    for(int i = 0; i < num_vertices - 1; i++)
        for(int j = 0; j < num_vertices; j++)
            for(int k = 0; k < V[j].size(); k++) {  // 인접한 정점들을 검사하여 경로 갱신
                int here = V[j][k].first;
                int cost = V[j][k].second;

                if(dist[j] + cost < dist[here])
                    dist[here] = dist[j] + cost;
            }

    // 음의 순환이 있는지 확인
    for(int i = 0; i < num_vertices; i++)
        for(int k = 0; k < V[i].size(); k++){
            int here = V[i][k].first;
            int cost = V[i][k].second;

            if(dist[i] + cost < dist[here])
                return vector<int>(1, -1);
        }
    
    vector<int> result;
    for(int i = 0; i < num_vertices; i++)
        result.push_back(dist[i]);

    return result;
}

// 초기화
void init() {
    fill(dist, dist + MAX, INF);    //비용 초기화(제일 큰값)
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

int main()
{
  init();
  print(solution(5, {{0, 1, 4}, {0, 2, 3}, {0, 4, -6}, {1, 3, 5}, {2, 1, 2}, {3, 0, 7}, {3, 2, 4},{4, 2, 2}}, 0)); //출력값 : 0 -2 -4 3 -6
  init();
  print(solution(4, {{0, 1, 5}, {0, 2, -1}, {1, 2, 2}, {2, 3,-2}, {3, 0, 2}, {3, 1, 6}}, 0)); //출력값 : -1

  return 0;
}