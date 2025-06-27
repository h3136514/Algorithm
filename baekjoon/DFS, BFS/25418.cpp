#include <iostream>
#include <queue>

#define MAX 1000001
using namespace std;
int A, K, dp[MAX], CNT;
queue<pair<int, int>> q;

void bfs(){
    q.push({A, 0});
    dp[A] = 0;
    while(!q.empty()){
        int currentNum = q.front().first;
        int currentCnt = q.front().second;
        q.pop();

        if(currentNum > K || dp[currentNum] < currentCnt)
            continue;
        
        dp[currentNum] = currentCnt;

        q.push({currentNum+1, currentCnt+1});
        q.push({currentNum*2, currentCnt+1});
    }
}

// 정수 a를 k로 만들기
int main(){
    cin >> A >> K;
    // 초기화
    for(int i = A; i <= K; i++){
        dp[i] = MAX;
    }

    bfs();

    cout << dp[K] << "\n";

    return 0;
}