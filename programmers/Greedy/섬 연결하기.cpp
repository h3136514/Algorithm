#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> parents, ranks;

int find(int x) {
    if(parents[x] == x)
        return x;
    
    return parents[x] = find(parents[x]);
}

void unionSet(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);
    
    if(root1 != root2) {
        if(ranks[root1] < ranks[root2])
            parents[root1] = root2;
        else if(ranks[root1] > ranks[root2])
            parents[root2] = root1;
        else {
            parents[root2] = root1;
            ranks[root1]++;
        }
    }
}

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

// 최소의 비용으로 모든 섬이 서로 통행 가능하도록 만들 때 필요한 최소 비용을 반환 (costs의 길이: E, 시간복잡도 : O(ElogE))
int solution(int n, vector<vector<int>> costs) {
    parents.resize(n);
    ranks.resize(n, 0);
    
    for(int i = 0; i < n; i++)
        parents[i] = i;
    
    // 비용을 기준으로 간선 정렬
    sort(costs.begin(), costs.end(), compare);
    
    int answer = 0;
    for(auto edge : costs) {
        int cost = edge[2];
        int node1 = edge[0];
        int node2 = edge[1];
        
        //싸이클이 생성 안되기 위해
        if(find(node1) != find(node2)) {
            unionSet(node1, node2);
            answer += cost;
        }
    }
    
    return answer;
}


#include <iostream>

int main()
{
  cout << solution(4, {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}}) << endl; //출력값 : 4

  return 0;
}
