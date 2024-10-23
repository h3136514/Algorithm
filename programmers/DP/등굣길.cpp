#include <string>
#include <vector>
#include <queue>

using namespace std;
int N, M, num[101][101], dp[101][101];

// 집에서 학교까지 가는 길은 m x n 크기의 격자모양으로 주어질 때 오른쪽과 아래쪽으로만 움직여 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 반환
int solution(int m, int n, vector<vector<int>> puddles) {
    N = n;
    M = m;
    for(vector<int> v : puddles){
        num[v[1]][v[0]] = -1; // 물 웅덩이 표시
    }
    
    dp[1][1] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            int a = (num[i-1][j] != -1) ? dp[i-1][j] : 0;
            int b = (num[i][j-1] != -1) ? dp[i][j-1] : 0;
            
            dp[i][j] += (a+b) % 1000000007;
        }
    }
    
    return dp[N][M];
}