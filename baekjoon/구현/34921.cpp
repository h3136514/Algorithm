#include <iostream>

using namespace std;
int A, T, result;

// 덕후
int main(){
    cin >> A >> T;
    result = (10 + 2*(25- A + T)) < 0 ? 0 : (10 + 2*(25- A + T));

    cout << result << "\n";

    return 0;
}