#include <iostream>
#include <algorithm>

using namespace std;
int N, M, num[9], arr[9], visitied[9];

void dfs(int cnt) {
    if(cnt == M) {
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";

        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visitied[i]) {
            visitied[i] = 1;
            arr[cnt] = num[i];
            dfs(cnt+1);
            visitied[i] = 0;
        }
    }
}

int main() {

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> num[i];

    sort(num, num+N);   // 오른차순 정렬
    
    dfs(0);

    return 0;
}