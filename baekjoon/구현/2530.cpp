#include <iostream>

using namespace std;
int A, B, C, D;

// 인공지능 시계
int main(){
    cin >> A >> B >> C;
    cin >> D;

    A += D/3600;
    D %=3600;
    B += D/60;
    D %= 60;
    C += D;

    B += C/60;
    C %= 60;
    A += B/60;
    B %= 60;
    A %= 24;

    cout << A << " " << B << " " << C << "\n";

    return 0;
}