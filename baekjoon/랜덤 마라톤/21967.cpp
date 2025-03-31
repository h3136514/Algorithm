// 브루트포스, 투포인터
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, A[1000001], CNT;

// 세워라 반석 위에 
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	// 수열의 수의 범위 차이가 2이하인 최대 길이 계산(1~3, 2~4와 같이 A가 1~10까지이므로 가능)
	for (int s = 1; s <= 8; s++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] >= s && A[i] <= s + 2) {
				cnt++;
				CNT = max(CNT, cnt);
			}
			else
				cnt = 0;
		}
	}

	cout << CNT << "\n";
	
	return 0;
}