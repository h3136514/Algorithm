// 공평한 분배 2
#include <iostream>
#include <algorithm>
#include <vector>
 
#define INF 1000000001
 
using namespace std;
int T, N, K, num, differ = INF;
vector<int> v;
 
void init() {
    differ = INF;
    v.clear();
}
 
int main() {
    cin >> T;
    for (int j = 1; j <= T; j++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> num;
            v.push_back(num);
        }
 
        sort(v.begin(), v.end());
 
        for (int i = 0; i <= N - K; i++) {
            differ = min(differ, v[i + K - 1] - v[i]);
        }
 
        cout << "#" << j << " " << differ << "\n";
 
        init();
    }
 
    return 0;
}