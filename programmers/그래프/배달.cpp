#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 20000000    //최대 가중치 (2000 X 10000)
#define MAX 2001   // 최대 노드 갯수 
using namespace std;
vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>> q;
int distances[MAX];  //노드별 최소비용
int cnt;

// 다익스트라 알고리즘
void dijkstra(int start) {
    cnt = 0;
    distances[start] = 0;
    q.push({0, start});
    
    while(!q.empty()) {
        int cost = -q.top().first; //제일 작은 비용
        int here = q.top().second; //해당 노드
        q.pop();
        
        // 이미 더 짧은 경로를 알고 있다면 무시
        if(distances[here] < cost)
            continue;
        
        // 인접한 정점들을 검사하여 경로 갱신
        for(int i = 0; i < v[here].size(); i++) {
            int next =  v[here][i].first;
            int nextCost = v[here][i].second + cost;
            
            //작은비용 갱신
            if(distances[next] > nextCost) {
                distances[next] = nextCost;
                q.push({-nextCost, next});
            }
        } 
    }
    
}

// 초기화
void init() {
    fill(distances, distances + MAX, INF);   //비용 초기화(제일 큰값)

    for(int i = 0; i < MAX; i++)
        v[i].clear();
}

// N개의 마을 중에서 K 시간 이하로 배달이 가능한 마을에서만 음식 주문을 받을 때, 음식 주문을 받을 수 있는 마을의 개수를 반환(road의길이: E, 시간 복잡도 : O((N+E)logN))
int solution(int N, vector<vector<int> > road, int K) {
    init();
    
    // 그래프 구성
    for(int i = 0; i < road.size(); i++) {
        int node1 = road[i][0];
        int node2 = road[i][1];
        int cost = road[i][2];
        // 양반향 모두 동일한 가중치 입력
        v[node1].push_back({node2, cost});
        v[node2].push_back({node1, cost});
    } 
    
    dijkstra(1);
    
    // K 이하의 시간에 배달이 가능한 마을의 개수
    for(int i = 1; i <= N; i++) {
        if(distances[i] <= K)
            cnt++;
    }
    
    return cnt;
}



#include <iostream>

int main()
{
  
  cout << solution(5, {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}}, 3) << endl; //출력값 : 4
  cout << solution(6, {{1, 2, 1}, {1, 3, 2}, {2, 3, 2}, {3, 4, 3}, {3, 5, 2}, {3, 5, 3}, {5, 6, 1}}, 4) << endl; //출력값 : 4
  return 0;
}