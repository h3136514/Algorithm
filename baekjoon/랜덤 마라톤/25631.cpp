#include <iostream>
#include <unordered_map>

using namespace std;
int N, a, CNT;
unordered_map<int,int> m;

// 마트료시카 합치기
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		m[a]++;
		CNT = max(CNT, m[a]);
	}

	cout << CNT << "\n";

	return 0;
}