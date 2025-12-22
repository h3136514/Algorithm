#include <iostream>
#include <algorithm>

using namespace std;
int a, b, c, d, e, result = -50;

// 상근날드
int main(){
    cin >> a >> b >> c >> d >> e;
    result += min({a, b, c});
    result += min(d, e);

    cout << result << "\n";

    return 0;
}