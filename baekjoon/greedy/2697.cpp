#include <iostream>
#include <string>
#include <queue>

using namespace std;
int T, targetIdx;
priority_queue<int> q1, q2;
string s, answer;

// 다음수 구하기 
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		answer = "";
		targetIdx = -1;
		cin >> s;
	
		for (int j = s.size() - 1; j >= 1; j--) {
			int a = s[j] - '0';
			int b = s[j - 1] - '0';
			if (a > b) {
				targetIdx = j - 1;	//뒤에서부터 내림차순이 시작되는 지점
				break;
			}
		}

		if (targetIdx == -1)
			answer = "BIGGEST";
		else {
			answer = s.substr(0, targetIdx);	// 지점 전까지 복사

			int a = s[targetIdx] - '0';
			q2.push(-a);
			for (int j = targetIdx+1; j < s.size(); j++) {
				q1.push(-(s[j] - '0'));
			}

			while (!q1.empty()) {
				int b = -q1.top();
				q1.pop();
				if (a != -1 && a < b) {	//  해당 지점보다 크면서 가장 작은 수 하나 선택
					answer += (b + '0');
					a = -1;
					continue;
				}
				
				q2.push(-b);
			}

			while (!q2.empty()) {	// 나머지 오른차 순으로 삽입
				answer += (-q2.top() + '0');
				q2.pop();
			}
		}
		
		cout << answer << "\n";
	}

	return 0;
}