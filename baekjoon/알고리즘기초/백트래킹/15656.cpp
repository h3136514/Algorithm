#include <iostream>
#include <algorithm>

using namespace std;
int N, M, num[9], arr[9];

void dfs(int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";

        return;
    }

    for(int i = 0; i < N; i++) {
        arr[cnt] = num[i];
        dfs(cnt+1);
        
    }
}

//자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하여라(단, N개의 자연수는 모두 다른 수이고 같은 수를 여러 번 골라도 된다. 고른 수열은 오른차순이어야 한다.)
int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> num[i];

    sort(num, num+N);
    dfs(0);

    return 0;
}