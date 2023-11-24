#include <iostream>
#include <string>
#include <vector>
#define INF 10001

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int dp[151][151]; // dp[alp][cop] := 최소 공부 시간
    fill(&dp[0][0], &dp[150][151], INF);
    
    int goal_alp = 0, goal_cop = 0;
    for(auto p : problems) {
        goal_alp = max(goal_alp, p[0]);
        goal_cop = max(goal_cop, p[1]);
    }
    alp = min(alp, goal_alp); // 4, 7, 8, 10 TC
    cop = min(cop, goal_cop);

    dp[alp][cop] = 0;
    for(int i=alp; i<=goal_alp; i++) {
        for(int j=cop; j<=goal_cop; j++) {
            if (i < goal_alp) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            if (j < goal_cop) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);
            for(auto p : problems) {
                if ((p[0] <= i) && (p[1] <= j)) {
                    int next_alp = min(i+p[2], goal_alp);
                    int next_cop = min(j+p[3], goal_cop);
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j]+p[4]);
                }
            }
        }
    }
    
    return dp[goal_alp][goal_cop];
}

int main() {
    int alp1 = 10;
    int cop1 = 10;
    vector<vector<int>> problems1 = {{10, 15, 2, 1, 2}, {20, 20, 3, 3, 4}};
    cout << solution(alp1, cop1, problems1) << endl;  // 출력: 15

    int alp2 = 0;
    int cop2 = 0;
    vector<vector<int>> problems2 = {{0, 0, 2, 1, 2}, {4, 5, 3, 1, 2}, {4, 11, 4, 0, 2}, {10, 4, 0, 4, 2}};
    cout << solution(alp2, cop2, problems2) << endl;  // 출력: 13

    return 0;
}