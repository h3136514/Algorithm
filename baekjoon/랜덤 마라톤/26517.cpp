// 수학
#include <iostream>

using namespace std;
long long k, a, b, c, d;

int main(){
    cin >> k;
    cin >> a >> b >> c >> d;

    if(a*k+b == c*k+d)
        cout << "Yes " << a*k+b << "\n";
    else
        cout << "No\n";

    return 0;
}