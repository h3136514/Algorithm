#include <iostream>

using namespace std;
int N, S, sumCnt, num[21], arr[21], visitied[21];

void dfs(int cnt, int idx, int m) {
    if(cnt == m) {
        int sum = 0;
        for(int i = 0; i < m; i++)
            sum += arr[i];
        if(sum == S)
            sumCnt++;

        return;
    }

    for(int i = idx; i < N; i++) {
        if(!visitied[i]) {
            visitied[i] = 1;
            arr[cnt] = num[i];
            dfs(cnt+1, i+1, m);
            visitied[i] = 0;
        }
    }
}

int main() {

    cin >> N >> S;
    
    for(int i = 0; i < N; i++) 
        cin >> num[i];

    // 1~N까지 갯수의 모든 부분수열을 탐색
    for(int i = 1; i <= N; i++)
        dfs(0, 0, i);
    
    cout << sumCnt;

    return 0;
}