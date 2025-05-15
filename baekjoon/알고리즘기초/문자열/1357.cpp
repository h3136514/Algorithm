// 구현, 문자열
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string a, b, sum;

// 뒤집힌 덧셈
int main(){
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int rSum =stoi(a) + stoi(b);

    sum = to_string(rSum);
    reverse(sum.begin(), sum.end());

    cout << stoi(sum) << "\n";

    return 0;
}