#include <iostream>

using namespace std;
long long A, B, sum;

// 이상한 기호
int main(){
    cin >> A >> B;
    sum = (A+B)*(A-B);

    cout << sum << "\n";

    return 0;
}