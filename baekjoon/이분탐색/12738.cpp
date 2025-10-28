#include <iostream>
#include <vector>

using namespace std;
int N, CNT;
vector<int> A, result;

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

// 가장 긴 증가하는 부분 수열 3
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    result.push_back(A[0]);
    for (int i = 1; i < N; i++) {
        if (result.back() < A[i]) {
            result.push_back(A[i]);
        }
        else {
            int idx = idxBinarySearch(A[i]);
            result[idx] = A[i];
        }
    }

    cout << result.size() << "\n";

    return 0;
}