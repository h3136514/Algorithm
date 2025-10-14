#include <iostream>

using namespace std;
int N, K, cnt[5], num[6][2], s = 1, b = 1;

// 참외밭
int main() {
    cin >> K;

    for (int i = 0; i < 6; i++) {
        cin >> num[i][0] >> num[i][1];
        cnt[num[i][0]]++;
    }

    for (int i = 0; i < 6; i++){
        // 한번만 나옴(전체 삼각형)
        if(cnt[num[i][0]] == 1){
            b *= num[i][1];
            continue;
        }

        int next = (i+1) % 6;
        int nextNext = (i+2) % 6;
        // 현재와 다다음꺼의 방향이 같으면 => 꺽임(그중간이 작은 삼각형 너비/높이)
        if(num[i][0] == num[nextNext][0]){
            s *= num[next][1];
        }
    }

    cout << (b-s)*K << "\n";
  
    return 0;
}
