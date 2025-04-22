#include <iostream>

using namespace std;
int N, M, startX, endX, num[10001], sum, CNT;

// 수들의 합 2
int main() {
	cin >> N  >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	while (startX <= endX && endX <= N) {	// endX <= N인 이유 => 마지막 요소를 처리한 후에도 (sum > M 일때)startX값을 이동해서 비교해야 될 수 있으므로 
		if (sum > M) {
			sum -= num[startX++];
		}
		else if(sum < M) {
			sum += num[endX++];
		}

		if (sum == M) {
			CNT++;
			sum += num[endX++];
		}
	}

	cout << CNT << "\n";

	return 0;
}