// 수학, 구현
#include <iostream>
#include <vector>

using namespace std;
int N, Q, a, b, x, s, idx =1;
vector<int> v;

// 실제 위치 반환
int factIdx(int num) {
	int r = idx + num;
	if (r > N)
		r -= N;
	else if (r < 1)
		r += N;
	
	return r;
}

// 현재 수열 출력
void printV() {
	for (int i = idx; i <= N; i++)
		cout << v[i] << " ";

	for (int i = 1; i < idx; i++)
		cout << v[i] << " ";

	cout << "\n";
}

// 수열과 시프트 쿼리
int main() {
	cin >> N >> Q;
	v.resize(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < Q; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> x;
			v[factIdx(b-1)] += x;
		}
		else {
			cin >> s;
			if (a == 2) {	// 오른쪽 s칸 이동
				idx = factIdx(N-s);
			}
			else {		// 왼쪽 s칸 이동
				idx = factIdx(s);
			}
		}
	}

	printV();

	return 0;
}