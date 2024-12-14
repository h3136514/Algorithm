// 구현, 문자열
#include <iostream>
#include <string>

using namespace std;
string a, b, c;

// A + B - C
int main(){
    cin >> a >> b >> c;

    cout << stoi(a) + stoi(b) - stoi(c) << "\n";
    cout << stoi(a+b) - stoi(c) << "\n";

    return 0;
}
