#include <iostream>
#include <vector>
#include <string>

using namespace std;
int K, a, b, sum;
string wheel[4];    // 톱니 바퀴
vector<char> v[3]; // 마주보는 톱니 번호 저장

// 시계 방향 회전
void right(int r) {
	char tmp1 = wheel[r][7];
    char tmp2;
	for (int i = 0; i < 8; i++) {
        tmp2 = wheel[r][i];
		wheel[r][i] = tmp1;
		tmp1 = tmp2;
	}

}

// 반시계 방향 회전
void left(int r) {
	char tmp1 = wheel[r][0];
    char tmp2;
	for (int i = 7; i >= 0; i--) {
        tmp2 = wheel[r][i];
		wheel[r][i] = tmp1;
		tmp1 = tmp2;
	}
}

// 톱니바퀴의 점수의 합 출력
void cal() {
	int idx = 1;
	for (int i = 0; i < 4; i++) {
		sum += (wheel[i][0] == '1') ? idx : 0;
		idx *= 2;
	}

	cout << sum << "\n";
}


// 톱니바퀴의 마주보는 상태 저장
void setWheel() {
	for (int i = 0; i < 3; i++) {
		v[i][0] = wheel[i][2];
		v[i][1] = wheel[i + 1][6];
	}
}

// 톱니바퀴 회전
void rotateWheel(int num, int r) {
	// 해당 톱니 회전
	if (r == 1)
		right(num - 1);
	else
		left(num - 1);

	if (num == 1) {
		for (int i = 0; i < 3; i++) {
			if (v[i][0] == v[i][1])
				break;
			if (r == 1) {
				r = -1;
				left(i + 1);
			}
			else {
				r = 1;
				right(i + 1);
			}
		}
	}
	else if (num == 2) {
		// 왼쪽 확인
		if (v[0][0] != v[0][1]) {
			if (r == 1)
				left(0);
			else
				right(0);
		}
		// 오른쪽 확인
		for (int i = 1; i < 3; i++) {
			if(v[i][0] == v[i][1])
				break;
			if (r == 1) {
				r = -1;
				left(i + 1);
			}
			else {
				r = 1;
				right(i + 1);
			}
		}

	}
	else if (num == 3) {
		// 오른쪽 확인
		if (v[2][0] != v[2][1]) {
			if (r == 1)
				left(3);
			else
				right(3);
		}
		// 왼쪽 확인
		for (int i = 1; i >= 0; i--) {
			if (v[i][0] == v[i][1])
				break;

			if (r == 1) {
				r = -1;
				left(i);
			}
			else {
				r = 1;
				right(i);
			}
		}
	
	}
	else if (num == 4) {
		for (int i = 2; i >= 0; i--) {
			if (v[i][0] == v[i][1])
				break;

			if (r == 1) {
				r = -1;
				left(i);
			}
			else {
				r = 1;
				right(i);
			}
		}
	}
	

	setWheel();
}

// 톱니바퀴
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> wheel[i];
	}
	// 톱니바퀴의 초기 마주보는 상태 저장
	for (int i = 0; i < 3; i++) {
		v[i].push_back(wheel[i][2]);
		v[i].push_back(wheel[i + 1][6]);
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		rotateWheel(a, b);
	}

	cal();
	
	return 0;
}