// 그리디
#include <iostream>
#include <vector>

using namespace std;
int N, K, hambuger[20001], CNT;
char c;
vector<int> P;

// 햄버거 분배
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c == 'H')
			hambuger[i] = 1;
		else
			P.push_back(i);
	}

	for (int i = 0; i < P.size(); i++) {
		int start = (P[i] - K) < 0 ? 0 : P[i] - K;
		int end = (P[i] + K) >= N ? N - 1 : P[i] + K;

		for (int j = start; j <= end; j++) { // 현재위치-K ~ 현재위치+K 중 햄버거가 있을 경우
			if (hambuger[j]) {
				hambuger[j] = 0;
				CNT++;
				break;
			}
		}
	}

	cout << CNT << "\n";

	return 0;
}