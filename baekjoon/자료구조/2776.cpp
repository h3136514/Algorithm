// https://www.acmicpc.net/problem/2776
#include <iostream>
#include <map>

using namespace std;
int T, N, M, num;
map<int, bool> m;

// 암기왕
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> num;
            m[num] = true;
        }

        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> num;
            if (m.find(num) == m.end())
                cout << "0\n";
            else
                cout << "1\n";
        }

        m.clear();
    }
    

    return 0;
}