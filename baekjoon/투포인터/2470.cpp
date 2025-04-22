#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2000000001
using namespace std;
int N, startX, endX, sum, minDiffer = INF, result[2];
vector<int> num;

// 두 용액
int main() {
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	endX = N - 1;
	while (startX < endX) {
		sum = num[startX] + num[endX];

		if (abs(sum) < minDiffer){	// 현재까지 0 에 가장 가까웠던 합
			minDiffer = abs(sum);
			result[0] = num[startX];
			result[1] = num[endX];

			if (sum == 0)
				break;
		}

		if (sum < 0)
			startX++;
		else
			endX--;
	}
	
	cout << result[0] << " " << result[1] << "\n";

	return 0;
}