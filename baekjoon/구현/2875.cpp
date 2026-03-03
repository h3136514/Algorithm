#include <iostream>

using namespace std;
int N, M, K, cnt;

// 대회 or 인턴
int main(){
    cin >> N >> M >> K;
    for(int i = 0; i <= K; i++){
        int a = (N - i) / 2;
        int b = M - (K - i);
        if(cnt < min(a, b))
            cnt = min(a, b);
    }
    cout << cnt << '\n';

    return 0;
}

