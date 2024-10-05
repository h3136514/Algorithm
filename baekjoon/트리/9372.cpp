#include <iostream>
#include <vector>

using namespace std;
int N, M, T, a, b;

// 상근이의 여행
int main() {
    cin >> T;

    while(0 < T--) {
        cin >> N >> M;
        for(int i =0; i < M; i++) {
            cin >> a >> b;
        }

        cout << N-1 << "\n";    //왕복을 하기위한 가장 적은 간선을 연결해야 하므로
    }

    return 0;
}
