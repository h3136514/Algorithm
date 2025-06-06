// 수학
#include <iostream>

using namespace std;
double a, b;

// 가희와 방어율 무시
int main(){
    cin >> a >> b;
    double cal = (b != 0) ? (a - a*b/100): a;

    int result = (cal >= 100) ? 0 : 1;
    cout << result << "\n";

    return 0;
}