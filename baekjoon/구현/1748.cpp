#include <iostream>

using namespace std;
int N, sum, CNT = 1;

// 수 이어 쓰기 1
int main() {
    cin >> N;

    int tmp = N;
    int i = 10;
    while (tmp > 0) {
        tmp /= 10;
        if (tmp > 0) {
            sum += (i - i/10)* CNT;
            i *= 10;
        }
        CNT++;
    }

    sum += (CNT - 1) * (N - i / 10 + 1);

    cout << sum << "\n";

    return 0;
}