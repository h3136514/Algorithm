#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v[101];
int min_dif, cnt, visitied[101];

void dfs(int start) {
    // 이미방문했으면
    if(visitied[start])
        return;
    
    visitied[start] = 1;
    cnt++;
    for(int i = 0; i < v[start].size(); i++) {
        dfs(v[start][i]);
    }
}

void init() {
    fill(visitied, visitied + 101, 0);
    cnt = 0;
}

// 송전탑의 개수 n, 전선들 중 하나를 끊어서 송전탑 개수가 가능한 비슷하도록 두 전력망으로 나누었을 때, 두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 반환 (시간 복잡도 : O(N^2))
int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    for(auto wire : wires) {
        int a = wire[0];
        int b = wire[1];
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    min_dif = 100;
    for(auto wire : wires) {
        int a = wire[0];
        int b = wire[1];
        
        // 특정 전선을 임시로 삭제
        v[a].erase(remove(v[a].begin(), v[a].end(), b), v[a].end());
        v[b].erase(remove(v[b].begin(), v[b].end(), a), v[b].end());
        
        dfs(a);
        int cnt_a = cnt;
        int cnt_b = n - cnt_a;
        
        // 현재까지 구한 송전탑의 차의 절대값의 최소값과 현재 값중 더 적은값을 택함
        min_dif = min(min_dif, abs(cnt_a -cnt_b));
        
        // 임시로 제거했던 제거했던 전선을 복구
        v[a].push_back(b);
        v[b].push_back(a);
        init(); // 방문 초기화
    }
    
    return min_dif;
}


#include <iostream>


int main()
{
  
  cout << solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}}) << endl; //출력값 : 3
  return 0;
}