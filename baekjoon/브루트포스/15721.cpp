#include <iostream>

using namespace std;
int A, T, bbun = 0, degi = 0, n = -1;
bool isD;

// 구하고자 하는 T번째 “뻔”(false), “데기”(true)에 도달유무
bool checkD(bool isBd){ 
    if ((!isBd &&!isD && bbun == T) ||(isBd && isD && degi == T)){
        cout << n % A;  // 원탁에서 몇 번째에 있는지 출력
        return true;
    }
    return false;
}

int main(void) {
	cin >> A >> T >> isD;

	int cnt = 2;
	while (1) {
		for (int i = 0; i < 2; i++) {
			bbun++; n++;
			if (checkD(false)) {
				return 0;
			}
			degi++; n++;
			if (checkD(true)) {
				return 0;
			}
		}

		for (int i = 0; i < cnt; i++) {
			bbun++; n++;
			if (checkD(false)) {
				return 0;
			}
		}

		for (int i = 0; i < cnt; i++) {
			degi++; n++;
			if (checkD(true)) {
				return 0;
			}
		}

		cnt++;
	}
	
}