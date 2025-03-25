// 자료구조, 우선순위 큐
#include <iostream>
#include <queue>

using namespace std;
int N, M, K, num, cnt[100001];
priority_queue<int> q[200001];

// 회전초밥
int main() {
	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		cin >> K;

		for(int j = 0; j < K; j++){
			cin >> num;
			q[num].push(-i);
		}
	}

	for(int i = 0; i < M; i++) {
		cin >> num;

		if (q[num].empty())
			continue;

		cnt[-q[num].top()]++;
		q[num].pop();
	}

	for (int i = 0; i < N; i++) {
		cout << cnt[i] << " ";
	}
	cout << "\n";



	return 0;
}