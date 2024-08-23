#include <iostream>

using namespace std;
int N, M, arr[8];

void dfs(int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";

        return;
    }

    for(int i = 1; i <= N; i++) {
        arr[cnt] = i;
        dfs(cnt+1);
    }

}

// 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하여라(단, 같은 수를 여러 번 골라도 된다.)
int main() {

    cin >> N >> M;
    dfs(0);

    return 0;
}