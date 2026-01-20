#include <iostream>

using namespace std;
int N, a, b, sum;

// 사과
int main(){
    cin >> N;
    while(N--){
        cin >> a >> b;
        b %= a;
        sum += b;
    }

    cout << sum << "\n";

    return 0;
}