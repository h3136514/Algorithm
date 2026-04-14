// https://www.acmicpc.net/problem/9019
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[10000];
int parent[10000];
char parentCmd[10000];

int D(int n) { return (n * 2) % 10000; }
int S(int n) { return n == 0 ? 9999 : n - 1; }
int L(int n) { return (n % 1000) * 10 + n / 1000; }
int R(int n) { return (n % 10) * 1000 + n / 10; }

string bfs(int a, int b) {
    fill(visited, visited + 10000, false);
    queue<int> q;
    visited[a] = true;
    parent[a] = -1;
    q.push(a);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == b) break;

        int nexts[4] = {D(cur), S(cur), L(cur), R(cur)};
        char cmds[4] = {'D', 'S', 'L', 'R'};

        for (int i = 0; i < 4; i++) {
            int nx = nexts[i];
            if (!visited[nx]) {
                visited[nx] = true;
                parent[nx] = cur;
                parentCmd[nx] = cmds[i];
                q.push(nx);
            }
        }
    }

    // 역추적
    string result = "";
    int cur = b;
    while (parent[cur] != -1) {
        result += parentCmd[cur];
        cur = parent[cur];
    }
    reverse(result.begin(), result.end());
    return result;
}

// DSLR
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }
}