#include <iostream>

using namespace std;
int N, K, startX, endX, num[100001], sum, maxSum;

// 수열
int main() {
	cin >> N  >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < K; i++) {
		sum += num[i];
	}
	maxSum = sum;
	endX = K - 1;
	while (endX+1 < N) {
		sum -= num[startX++];
		sum += num[++endX];

		maxSum = max(maxSum, sum);
	}

	cout << maxSum << "\n";

	return 0;
}