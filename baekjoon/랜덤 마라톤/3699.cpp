// 수학, 구현
#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;
int T, h, l, num, maxNum, CNT;
deque<int> q[51];
unordered_map<int, int> m;

void init() {
	for (int i = 1; i <= h; i++)
		while (!q[i].empty())
			q[i].pop_back();

	m.clear();
	CNT = 0;
	maxNum = 0;
}

// 주차 빌딩
int main() {
	cin >> T;
	while (T--) {
		cin >> h >> l;
		for (int i = 1; i <= h; i++) {
			for (int j = 0; j < l; j++) {
				cin >> num;
				if (num != -1) {
					m[num] = i;
					maxNum = max(maxNum, num);
				}

				q[i].push_back(num);
			}
		}
		
		for (int i = 1; i <= maxNum; i++) {
            int high = m[i];
            CNT += (high-1)*2*10;  // 층이동

            int cnt = 0;
            for(int j = 0; j < q[high].size(); j++){
                num = q[high].front();
                q[high].pop_front();

                if(num == i){
                    cnt = j;
                    q[high].push_front(-1);
                    break;
                }else
                    q[high].push_back(num);
            }


            CNT += (cnt <= l/2) ? cnt*5 : (l-cnt)*5;
		}


		cout << CNT << "\n";
		init();
	}

	return 0;
}