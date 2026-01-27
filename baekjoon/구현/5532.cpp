#include <iostream>

using namespace std;
int L, A, B, C, D, cnt;

// 방학 숙제
int main(){
    cin >> L >> A >> B >> C >> D;
    while(A > 0 || B > 0){
        A -= C, B -= D;
        cnt++;
    }

    cout << L - cnt << "\n";

    return 0;
}