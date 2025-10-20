#include <iostream>

#define INF 1000000001
using namespace std;
long long N, M, num[10000], s = 1, e, result = 0;

// 예산 (정해진 총액 이하에서 가능한 한 최대의 총 예산을 배정 할 때 배정된 예산들 중 최댓값인 정수를 출력)
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        e = max(num[i], e);
    }
    cin >> M;

    while (s <= e) {
        long long mid = (s + e) / 2;
        
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (num[i] >= mid) {
                sum += mid;
            }
            else {
                sum += num[i];
            }
        }

        if (sum <= M) {
            result = max(result, mid);
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}