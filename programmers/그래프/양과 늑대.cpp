#include <string>
#include <vector>

using namespace std;
vector<int> v[18];
int visited[18], sheep, wolf, maxSheep;

// 깊이 우선 탐색 (DFS)
void dfs(vector<int> cur, vector<int> info) {
    sheep = 0, wolf = 0;
    // 현재 방문한 경로를 기준으로 양과늑대의 개수
    for(int i = 0; i < cur.size(); i++)
        if(info[cur[i]] == 1)
            wolf++;
        else
            sheep++;
    
    // 늑대의 수가 양보다 많거나 같으면 종료  
    if(sheep <= wolf)
        return;
    
    // 최대 양의 수 갱신
    if(maxSheep < sheep)
        maxSheep = sheep;
    
    for (int i = 0; i < cur.size(); i++) {
        int node = cur[i];
        
        // 현재 노드와 인접한 노드를 순회
        for(int j = 0; j < v[node].size(); j++) {
            
            if(visited[v[node][j]])
                continue;
            
            visited[v[node][j]] = 1;
            cur.push_back(v[node][j]);
            dfs(cur, info);
            cur.pop_back();
            visited[v[node][j]] = 0;
        }
    }    
    
}

// 2진 트리 모양 초원의 각 노드에 늑대와 양이 한 마리씩 놓여 있습니다.  모을 수 있는 양은 최대 몇 마리인지 반환(단, 중간에 모은 양의 수보다 늑대의 수가 같거나 더 많아지면 바로 모든 양을 잡아먹어 버립니다.)(시간 복잡도 : O(N^2))
int solution(vector<int> info, vector<vector<int>> edges) {
    for(int i = 0; i < info.size() - 1; i++) {
        v[edges[i][0]].push_back(edges[i][1]);
    }
    
    dfs({0}, info);
    
    return maxSheep;
}


#include <iostream>

// 초기화
void init()
{   
    for(int i = 0; i < 18; i++) {
        v[i].clear();
        visited[i] = 0;
    }
    maxSheep = 0;
    
}

int main()
{
  cout << solution({0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}, 
                   {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}}
                  ) << endl; //출력값 : 5

  init(); // 전역변수를 초기화 해야함
  
  cout << solution({0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0}, 
                   {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 8}, {6, 9}, {9, 10}}
                  ) << endl; //출력값 : 5
    return 0;
}