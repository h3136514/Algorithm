// 수학, 사칙연산
#include <iostream>

using namespace std;
int T, N, C, CNT;

// 쿠키애호가
int main(){
    cin >> T;
    while(T--){
        cin >> N >> C;
        CNT = (N%C == 0) ? N/C : N/C + 1;
        cout << CNT << "\n";
    } 

    return 0;
}

