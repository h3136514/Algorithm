#include <iostream>
#include <vector>
using namespace std;

// 한동이는 공부가 하기 싫어!
int main() {
    int n;
    cin >> n;
    
    vector<int> next(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> next[i];
    }
    
    int bestStart = 1;
    int bestCount = 0;
    
    for (int start = 1; start <= n; start++) {
        vector<bool> visited(n + 1, false);
        int count = 0;
        int cur = start;
        
        while (!visited[cur]) {
            visited[cur] = true;
            count++;
            cur = next[cur];
        }
        
        if (count > bestCount) {
            bestCount = count;
            bestStart = start;
        }
    }
    
    cout << bestStart << endl;
    return 0;
}