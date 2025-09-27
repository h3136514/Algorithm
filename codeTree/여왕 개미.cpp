#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define INF 1000000000
using namespace std;
int Q, N, idx, comand, CNT = 1, searchCnt;
long long T = INF;
map<int, int> ants;
vector<int> v;

void init() {
	T = INF;
}

// 마을 건설
void makeFarm() {
	for (int i = 0; i < N; i++) {
		ants[CNT] = v[i];
		CNT++;
	}
}

// 개미집 건설
void addHosue() {
	ants[CNT++] = idx;
}

// 개미집 철거
void destoryHouse() {
	ants.erase(idx);
}

// 개미집 정찰
void searchHouse() {
	long long s = 0, e = INF;
	while (s <= e) {
		long long mid = (s + e) / 2;
		int cnt = 0;	// 투입되는 정찰병 수
		long long cover= 0;	// 커버구역

		for (auto r : ants) {
			int x = r.second;

			if (cover == 0) {// 초기 정찰병 투입
				cover = x + mid;
				cnt = 1;
				continue;
			}

			if (cover >= x) {
				continue;
			}

			cover = x + mid;
			cnt++;
		}

		if (searchCnt >= cnt) {
			T = min(T, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}

	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> Q;
	while (Q--) {
		cin >> comand;

		if (comand == 100) {
			cin >> N;
			v.resize(N);
			for (int i = 0; i < N; i++) {
				cin >> v[i];
			}
			makeFarm();
		}
		else if (comand == 200) {
			cin >> idx;
			addHosue();
		}
		else if (comand == 300) {
			cin >> idx;
			destoryHouse();
		}
		else {
			cin >> searchCnt;
			searchHouse();

			cout << T << "\n";
		}

		init();
	}

	return 0;
}