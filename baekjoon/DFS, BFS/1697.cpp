#include <iostream>
#include <queue>

#define MAX 100001
using namespace std;
queue<pair<int,int>> q;
int N, K, result, visitied[MAX];

bool check(int x) {
    return x >= 0 && x < MAX;
}

// BFS
int bfs(int start) {
    q.push({start, 0});
    visitied[start] = 1;

    while(!q.empty()) {
        int next = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(next == K){
            return cnt;
        }

        int a = next - 1;   // X-1 이동
        int b = next + 1;   // X+1 이동
        int c = next*2;     // X*2 이동
        
        if(check(a) && !visitied[a]) {
            visitied[a] = 1;
            q.push({a, cnt+1});
        }
        if(check(b) && !visitied[b]) {
            visitied[b] = 1;
            q.push({b, cnt+1});
        }
        if(check(c) && !visitied[c]) {
            visitied[c] = 1;
            q.push({c, cnt+1});
        }
    }
}

int main() {
    cin >> N >> K;
    
    result = bfs(N);

    cout << result << "\n";
    
    return 0;
}
