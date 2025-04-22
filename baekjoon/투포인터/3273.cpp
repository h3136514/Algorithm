#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, X, startX, endX, sum, CNT;
vector<int> num;

// 두 수의 합
int main() {
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	cin >> X;

	if (N == 1) {	// 하나는 쌍을 만들 수 없으므로
		cout << "0\n";
		return 0;
	}

	sort(num.begin(), num.end());

	endX = N - 1;
	while (startX < endX) {
		sum = num[startX] + num[endX];  // 맨앞(작은 값) + 맨뒤(큰 값)

		if (sum > X) {
			endX--;
		}
		else if (sum < X) {
			startX++;
		}

		if (sum == X) {
			CNT++;
			startX++;
			endX--;
		}
	}
	
	cout << CNT << "\n";

	return 0;
}