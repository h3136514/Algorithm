#include <string>
#include <vector>

using namespace std;
int dp[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 0; i < results.size(); i++){
        dp[results[i][0]][results[i][1]] = 1;
    }
    
    // 플로이드와샬 알고리즘(시간복잡도: O(N^3))
    for(int k = 1; k <= n; k++){     // k 는 거쳐가는 정점
        for(int i = 1; i <= n; i++){    // i 는 이긴다.(출발 정점)
            for(int j = 1; j <= n; j++){    // j 는 진다.(도착 정점)
                if(dp[i][k] && dp[k][j])
                    dp[i][j] = 1; 
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++){
            if(i == j)
                continue;
            
            sum += dp[i][j] + dp[j][i];
        }
        
        if(sum == n-1)  // 한 선수가 모든 선수들에 대해서 (이기든 지든)값을 가진다면 그 선수의 순위를 매길 수 있음
            answer++;
    }
    
    return answer;
}