#include <iostream>
#include <queue>
#include <map>

#define INF 987654321
using namespace std;
int N, M, CNT, sum, P[2];
map<int, int> dp;
queue<pair<int, int>> q;

void bfs(){
    q.push({0, 0});
    dp[0] = 0;

    while(!q.empty()){
        int currentV = q.front().first;
        int currentCnt = q.front().second;
        q.pop();

        if(dp[currentV] < currentCnt)
            continue;
        
        for(int i = 0; i < 2; i++){
            int iv = currentV + P[i];
            int icnt = currentCnt + 1;

            if(dp.find(iv) != dp.end() && dp[iv] > icnt){
                dp[iv] = icnt;
                q.push({iv, icnt});
            }
        }
    }

}

// 간단한 동전 문제 (Easy)
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }
    for(int i = -2000; i <= 2000; i++){
        dp[i] = INF;
    }

    if(N == 0){
        if(M != 0){
            CNT = -1;
        }
    }else if(N == 1){
        if(P[0] == 0){
            if(M != 0)
                CNT = -1;
        }else if(M % P[0] == 0 && M/P[0] >= 0){
            CNT = M/P[0];
        }else{
            CNT = -1;
        }
    }else{
        if(M != 0){
            bfs();

            if(dp[M] == INF)
                CNT = -1;
            else
                CNT = dp[M];
        }
    }

    cout << CNT << "\n";

    return 0;
}