#include <iostream>
#include <queue>

using namespace std;
int N, num, agoValue, sum;
priority_queue<pair<int, int>> q;

// 게임을 만든 동준이
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		q.push({ i, num });
	}

	agoValue = q.top().second;
	q.pop();
	while (!q.empty()) {
		num = q.top().second;
		q.pop();
		if (num >= agoValue) {
			sum += num - agoValue + 1;
			num = agoValue - 1;
		}

		agoValue = num;
	}

	cout << sum << "\n";

	return 0;
}