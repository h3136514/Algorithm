// [모의 SW 역량테스트] 보물상자 비밀번호
#include <iostream>
#include <set>
#include <string>
#include <cmath>

using namespace std;
int T, N, K, CNT;
string str;
set<string> s;

int accurate(string num) {
	int sum = 0, idx = 0;
	for (int i = num.size() -1; i >= 0; i--) {
		int a = 0;
		if (isalpha(num[i]))
			a = int(num[i]) - 55;
		else
			a = num[i] - '0';
		
		sum += a * pow(16, idx++);
	}
	return sum;
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		cin >> str;
		str += str;
		
		int strSize = N/4;
		for (int j = 0; j < N; j++) {
			string num = "";
			for (int l = j; l < j + strSize; l++) {
				num += str[l];
			}
			s.insert(num);
		}
		CNT = s.size() - K;
		int cnt = 0;
		for (string num : s) {
			if (cnt++ == CNT) {
				cout << "#" << i << " " << accurate(num) << "\n";
				break;
			}
		}
		s.clear();

	}

	return 0;
}