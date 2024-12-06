#include <iostream>
#include <algorithm>

using namespace std;
int N, M, packet, one, minPacket = 1001, minOne = 1001;

// 기타줄
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> packet >> one;
        minPacket = min(minPacket, packet);
        minOne = min(minOne, one);
    }
    // 다 낱게 구매
    int a = N * minOne;
    // 다 패키지 구매
    int b = (N%6 == 0) ? N/6 * minPacket : (N/6 + 1)* minPacket;
    // 패키지 + 낱개 구매
    int c =  N/6 * minPacket + N%6 * minOne;

    cout << min({a, b, c}) << "\n";

    return 0;
}