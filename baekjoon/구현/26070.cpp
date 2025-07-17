#include <iostream>

using namespace std;
int A, B, C, X, Y, Z;
long long CNT;

// 곰곰이와 학식
int main() {
    cin >> A >> B >> C;
    cin >> X >> Y >> Z;
    
    if (A < X) {
        CNT += A;
        A = 0;
        X -= A;
        Y += X / 3;;
    }
    else {
        CNT += X;
        A -= X;
        X = 0;
    }

    if (B < Y) {
        CNT += B;
        Y -= B;
        B = 0;
        Z += Y/3 ;
    }
    else {
        CNT += Y;
        Y = 0;
        B -= Y;
    }

    if (C < Z) {
        CNT += C;
        Z -= C;
        C = 0;
        X += Z/ 3;
        if (A > 0)
            CNT += ((X >= A) ? A : X);
    }
    else {
        CNT += Z;
    }

    cout << CNT << "\n";

    return 0;
}