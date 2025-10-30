#include <iostream>

using namespace std;
int N, M, maxNum, num[100001];
long long sum, K;

void binarySearch() {
	long long s = maxNum, e = sum;
	K = sum;
	while (s <= e) {
		long long mid = (s + e) / 2;
		int cnt = 0;
		long long money = 0;
		for (int i = 0; i < N; i++) {
			if (money < num[i]) {
				money = mid;
				cnt++;
			}
			money -= num[i];
		}

		if (M >= cnt) {
			K = min(K, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

}

// 용돈 관리
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		maxNum = max(maxNum, num[i]);
		sum += num[i];
	}
	
	binarySearch();

	cout << K << "\n";

	return 0;
}