#include <iostream>
#include <queue>

#define INF 200001
using namespace std;
int N, K, CNT, maxValue, dp[INF];
queue<pair<int, int>> q;
// 초기화
void init(){
    maxValue = INF;
    for(int i = 0; i < INF; i++)
        dp[i] = INF;
}

// 범위확인
bool check(int x){
    return x >= 0 && x < INF;
}

void bfs(){
    dp[N] = 0;
    q.push({N, 0});

    while(!q.empty()){
        int currentX = q.front().first;
        int currentCNT = q.front().second;
        q.pop();

        if(currentX == K){
            if(maxValue == currentCNT)
                CNT++;
            if(maxValue > currentCNT){
                maxValue = currentCNT;
                CNT = 1;
            }

            continue;
        }

        if(dp[currentX] < currentCNT)
            continue;

        if(check(currentX -1) && dp[currentX -1] >= currentCNT + 1){
            dp[currentX -1] = currentCNT + 1;
            q.push({currentX -1, currentCNT + 1});
        }
        if(check(currentX +1) && dp[currentX +1] >= currentCNT + 1){
            dp[currentX +1] = currentCNT + 1;
            q.push({currentX +1, currentCNT + 1});
        }
        if(check(currentX*2) && dp[currentX*2] >= currentCNT + 1){
            dp[currentX *2] = currentCNT + 1;
            q.push({currentX*2, currentCNT + 1});
        }
    }
}

// 숨바꼭질 2
int main(){
    cin >> N >> K;
    init();
    bfs();

    cout << dp[K] << "\n";
    cout << CNT << "\n";

    return 0;
}
