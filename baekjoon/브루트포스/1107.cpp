#include <iostream>

using namespace std;
int N, M, num[10], current = 100, totalCnt, numCnt = 7, cnt;

// 리모컨으로 이동가능한지 확인
bool check(int n) {
	if (n == 0) {
		if(num[0])
			return false;
		else {
			numCnt = 1;
			return true;
		}
	}
	int c = 0;
	while (n > 0) {
		int target = n % 10;
		if (num[target])
			return false;

		c++;
		n /= 10;
	}

	numCnt = min(numCnt, c);
	return true;
}

// 리모컨
int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		num[a] = 1;
	}

	totalCnt = abs(N - current);	// +, - 이동 횟수
	while (true) {
		if (N == 100 || cnt > totalCnt)
			break;

		int upNum = N + cnt;
		int downNum = (N - cnt > 0) ? N - cnt : 0;

		if (check(downNum) || check(upNum))	// 낮은 수를 눌렀을 때가 더 수가 적으므로 downNum 먼저 확인
			break;
		
		cnt++;
	}

	totalCnt = min(totalCnt, numCnt + cnt);

	cout << totalCnt << "\n";

	return 0;
}