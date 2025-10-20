#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> num, result;

// 이분탐색 => LIS 수열을 이루는 원소 중 탐색 원소와 '가장 차이가 안나면서 더 큰' 원소를 찾음
int idxBinarySearch(int a) {
    int s = 0, e = result.size() - 1;
    int idx = e;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (result[mid] >= a) {
            idx = min(idx, mid);
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }

    return idx;
}

// 가장 긴 증가하는 부분 수열 2 (LIS 유형(길이가 긴))
int main() {
    cin >> N;
    num.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    
    result.push_back(num[0]);
    for (int i = 1; i < N; i++) {
        if (result.back() < num[i]) {
            result.push_back(num[i]);
        }
        else {
            int idx = idxBinarySearch(num[i]);
            result[idx] = num[i];
        }
    }

    cout << result.size() << "\n";

    return 0;
}