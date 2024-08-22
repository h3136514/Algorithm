#include <iostream>

using namespace std;
int N, M, arr[9], visitied[9];

void dfs(int num, int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << endl;

        return;
    }
    
    // 재귀 호출에서, 현재 뽑은 원소의 이전값들은 고려하지 않게끔 보냄 => 오른차 순
    for(int i = num; i <= N; i++) {
        if(!visitied[i]) {
            visitied[i] = 1;
            arr[cnt] = i;
            dfs(i + 1, cnt + 1);
            visitied[i] = 0;
        }
    }    
}

// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하여라(단, 고른 수열은 오름차순이야되고 중복 수열은 X)
int main() {

    cin >> N >> M;
    dfs(1, 0);

    return 0;
}