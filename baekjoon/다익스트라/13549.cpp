// 다익스트라
#include <iostream>
#include <queue>

#define MAX 200001
using namespace std;
int N, K, S, E, dp[100001];
int X[2] = {-1, 1};
priority_queue<pair<int, int>> pq; //비용, 위치

// 범위 계산
bool check(int x) {
    return x >= 0 && x <= 100000;
}

// 다익스트라
void dijkstra(int start) {
    pq.push({0, start});
    dp[start] = 0;
    
    while(!pq.empty()){
        int currentCost = -pq.top().first;
        int currentX = pq.top().second;
        pq.pop();
        
        if(currentCost > dp[currentX])
            continue;

        int ix, icost;
        for(int i=0; i<3; i++){
            if( i== 2){ // 뒤로 가는경우
                ix = 2*currentX;
                icost = currentCost;
            }
            else{ // 앞,뒤 한칸 가는경우
                ix = currentX+ X[i];
                icost = currentCost+1;
            }
        
            if(check(ix) && dp[ix] > icost){
                dp[ix] = icost;
                pq.push({-icost, ix});
            }
        }
    }
}

// 숨바꼭질 3
int main(void){
    cin >> N >> K;
    
    for(int i=0; i<100001; i++){
        dp[i] = MAX;
    }
    
    dijkstra(N);
    cout << dp[K] << "\n";
}