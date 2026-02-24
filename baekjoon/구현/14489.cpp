#include <iostream>

using namespace std;
int A, B, C;

// 치킨 두 마리
int main(){
    cin >> A >> B;
    cin >> C;

    if(A+B >= C*2)
        cout << (A+B)-(C*2) << "\n";
    else
        cout << A + B << "\n";

    return 0;
}