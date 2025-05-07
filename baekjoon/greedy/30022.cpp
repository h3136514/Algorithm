#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, A, B;
long long sum;
vector<pair<int, int>> v;
priority_queue<pair<int, int>> q;

// 행사 준비
int main() {
	cin >> N >> A >> B;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
		q.push({ abs(v[i].first - v[i].second), i });
	}

	while (!q.empty()) {
		int idx = q.top().second;
		q.pop();

		int a = v[idx].first;
		int b = v[idx].second;
		if (A == 0) {
			sum += b;
		}
		else if (B == 0) {
			sum += a;
		}
		else {
			if (a > b) {
				B--;
				sum += b;
			}
			else {
				A--;
				sum += a;
			}
		}
	}
	
	cout << sum << "\n";

	return 0;
}