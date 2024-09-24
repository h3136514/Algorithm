#include <iostream>

using namespace std;
int N, arr[9], visitied[9];

void dfs(int cnt) {
    if(cnt == N) {
        for(int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    for(int i = 1; i <= N; i++) {
        if(!visitied[i]) {
            visitied[i] = 1;
            arr[cnt] = i;
            dfs(cnt + 1);
            visitied[i] = 0;
        }
    }
}

int main() {
    cin >> N;
    dfs(0);

    return 0;
}