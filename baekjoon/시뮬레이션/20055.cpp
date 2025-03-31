#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, K, sum, num[201], robot[201], upIdx, downIdx, CNT = 1;
queue<int> q;

// 컨베이어 벨트 위의 로봇
int main() {
	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++) {
		cin >> num[i];
	}

	upIdx = 0;
	downIdx = N - 1;
	while (true) {
		// 1. 한칸 회전
		upIdx = (upIdx == 0) ? 2 * N - 1 : upIdx - 1;
		downIdx = (downIdx == 0) ? 2 * N - 1 : downIdx - 1;

		// 2. 로봇이동
		int robbotSize = q.size();
		for (int i = 0; i < robbotSize; i++) {
			int idx = q.front();
			q.pop();
			// 회전 후 내리는 위치에 있을 때
			if (idx == downIdx) {
				robot[idx] = 0;
				continue;
			}

			// 로봇 한칸 이동 가능한지 확인
			int nextIdx = (idx == 2 * N - 1) ? 0 : idx + 1;
			if (!robot[nextIdx] && num[nextIdx] >= 1) {
				// 내구도 감소
				num[nextIdx]--;
				if (num[nextIdx] == 0)
					sum++;

				robot[idx] = 0;
				// 이동한 위치가 내리는 위치가 아닐경우
				if (nextIdx != downIdx) {
					robot[nextIdx] = 1;
					q.push(nextIdx);

				}
			}
			else {
				q.push(idx);
			}
		}

		// 3. 로봇 올리기
		if (num[upIdx]) {
			num[upIdx]--;
			if (num[upIdx] == 0)
				sum++;

			q.push(upIdx);
			robot[upIdx] = 1;
		}

		// 4. 내구도가 0인 칸이 k개 이상이면 종료
		if (sum >= K)
			break;

		CNT++;
	}

	cout << CNT << "\n";

	return 0;
}