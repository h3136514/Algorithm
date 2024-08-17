#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int cntDungeon, sizeDungeon, visitied[8];

// 최대방문 던전수를 갱신하면서 깊이우선탐색으로 던전을 탐험
void backtrack(int n, int cnt, vector<vector<int>> dungeons) {
    // 남은 피로도가 0 이거나 던전 모두를 돌았을 때
    if(n == 0 || cnt == sizeDungeon){
        cntDungeon = max(cntDungeon, cnt);
        return;   
    }
    
    for(int i = 0; i < sizeDungeon; i++) {
        int a = dungeons[i][0]; // 최소 필요 피로도
        int b = dungeons[i][1]; // 소모 피로도
        // 이미 방문한 던전이거나,  최소 필요 피로도가 현재 남은 피로도 보다 많은 경우 
        if(visitied[i] || n < a)
            continue;
        
        visitied[i] = 1;
        backtrack(n-b, cnt+1, dungeons);
        visitied[i] = 0;
        
    }
    
    cntDungeon = max(cntDungeon, cnt);
}

// 하루에 한 번씩 탐험할 수 있는 던전이 여러개 있는데 이때 던전별 "최소 필요 피로도", "소모 피로도"가 존재할 때 유저가 탐험할수 있는 최대 던전 수를 반환 (시간복잡도 : O(N!))
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    sizeDungeon = dungeons.size();
    // 던전탐색 시작
    backtrack(k, 0, dungeons);
    
    return cntDungeon;
}


#include <iostream>


int main()
{
  cout << solution(80, {{80, 20}, {50, 40}, {30, 10}}) << endl; // 출력값 : 3
  return 0;
}