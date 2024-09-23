#include <vector>
#include <map>
#include <queue>

using namespace std;
map<int, int> m;     // 각 크기에 따른 귤의 개수는 세는
priority_queue<pair<int, int>> q;
int cnt;

// 한 상자에 담으려는 귤의 개수 k와 귤의 크기를 담은 배열 tangerine이 주어집니다. 귤 k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 반환
int solution(int k, vector<int> tangerine) {
    for(int i = 0; i < tangerine.size(); i++) {
        // 크기별로 귤의 개수를 셈 
        m[tangerine[i]]++;
    }
    
    // 각 귤의 개수를 기준으로 내림차순 배치
    for(auto it : m) {
        q.push({it.second, it.first});
    }

    // 귤의 개수 합이 k 이상 되는 순간 종료
    while(k > 0) {
        int numCnt = q.top().first;
        q.pop();
        
        k -= numCnt;
        cnt++;
    }
    
    return cnt;
}

// 테스트 코드
#include <iostream>


void init() {
    cnt = 0;
    m.clear();
    while(!q.empty())
        q.pop();
}

int main()
{
    cout << solution(6, {1, 3, 2, 5, 4, 5, 2, 3}) << endl; //출력값 : 3
    init(); 
    cout << solution(4, {1, 3, 2, 5, 4, 5, 2, 3}) << endl; //출력값 : 2
    init();
    cout << solution(2, {1, 1, 1, 1, 2, 2, 2, 3}) << endl; //출력값 : 1
  
    return 0;
}