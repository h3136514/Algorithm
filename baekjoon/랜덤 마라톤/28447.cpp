// 브루트포스
#include <iostream>

using namespace std;
int N, K, maxSum = -987654321, num[11][11], arr[11];

// k개의 조합수
void dfs(int idx, int cnt){
    if(cnt == K){
        int sum = 0;
        for(int i = 0; i < K-1; i++){
            for(int j = i+1; j < K; j++){
                sum += num[arr[i]][arr[j]];
            }
        }
        
        maxSum = max(maxSum, sum);
        return;
    }

    for(int i = idx; i < N; i++){
        arr[cnt] = i;
        dfs(i+1,cnt+1);
    }
}

// 마라탕 재료 고르기
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> num[i][j];
        }
    }
    if(K == 1)
        maxSum = 0;
    else
        dfs(0, 0);
    
    cout << maxSum << "\n";

    return 0;
}